/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "calculator.h"

#include <QtMath>



Calculator::Calculator()
    : sumInMemory(0.0), sumSoFar(0.0)
    , factorSoFar(0.0), waitingForOperand(true)
{
    pendingMultiplicativeOperator = Null;
    pendingAdditiveOperator = Null;
}


QString Calculator::display() {
    return m_display;
}


void Calculator::digitClicked(QString sNumber)
{
    int digitValue = sNumber.toInt();

    if (m_display == "0" && digitValue == 0.0)
        return;

    if (waitingForOperand) {
        m_display.clear();
        waitingForOperand = false;
    }
    m_display += QString::number(digitValue);
    emit displayChanged(m_display);
}


void Calculator::unaryOperatorClicked(Enum_Operations clickedOperator)
{
    double operand = m_display.toDouble();
    double result = 0.0;

    if (clickedOperator == SquareRoot) {
        if (operand < 0.0) {
            abortOperation();
            return;
        }
        result = std::sqrt(operand);
    } else if (clickedOperator == Square) {
        result = std::pow(operand, 2.0);
    } else if (clickedOperator == Inverse) {
        if (operand == 0.0) {
            abortOperation();
            return;
        }
        result = 1.0 / operand;
    }
    m_display = QString::number(result);
    emit displayChanged(m_display);
    waitingForOperand = true;
}


void Calculator::additiveOperatorClicked(Enum_Operations clickedOperator)
{
    double operand = m_display.toDouble();


    if (pendingMultiplicativeOperator != Null) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }

        m_display = QString::number(factorSoFar);
        emit displayChanged(m_display);
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator = Null;
    }

    if (pendingAdditiveOperator != Null) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }

        m_display = QString::number(sumSoFar);
        emit displayChanged(m_display);
    } else {
        sumSoFar = operand;
    }

    pendingAdditiveOperator = clickedOperator;
    waitingForOperand = true;
}


void Calculator::multiplicativeOperatorClicked(Enum_Operations clickedOperator)
{
    double operand = m_display.toDouble();

    if (pendingMultiplicativeOperator != Null) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }

        m_display = QString::number(factorSoFar);
        emit displayChanged(m_display);
    } else {
        factorSoFar = operand;
    }

    pendingMultiplicativeOperator = clickedOperator;
    waitingForOperand = true;
}


void Calculator::equalClicked()
{
    double operand = m_display.toDouble();

    if (pendingMultiplicativeOperator != Null) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator = Null;
    }
    if (pendingAdditiveOperator != Null) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        pendingAdditiveOperator = Null;
    } else {
        sumSoFar = operand;
    }


    m_display = QString::number(sumSoFar);
    emit displayChanged(m_display);
    sumSoFar = 0.0;
    waitingForOperand = true;
}


void Calculator::pointClicked()
{
    if (waitingForOperand) {

        m_display = "0";
        emit displayChanged(m_display);
    }
    if (!m_display.contains('.')) {

        m_display += tr(".");
        emit displayChanged(m_display);
    }
    waitingForOperand = false;
}


void Calculator::changeSignClicked()
{
    QString text = m_display;
    double value = text.toDouble();

    if (value > 0.0) {
        text.prepend(tr("-"));
    } else if (value < 0.0) {
        text.remove(0, 1);
    }

    m_display = text;
    emit displayChanged(m_display);
}


void Calculator::backspaceClicked()
{
    if (waitingForOperand)
        return;

    QString text = m_display;
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
        waitingForOperand = true;
    }

    m_display = text;
    emit displayChanged(m_display);
}


void Calculator::clear()
{
    if (waitingForOperand)
        return;


    m_display = "0";
    emit displayChanged(m_display);
    waitingForOperand = true;
}


void Calculator::clearAll()
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator = Null;
    pendingMultiplicativeOperator = Null;

    m_display = "0";
    emit displayChanged(m_display);
    waitingForOperand = true;
}


void Calculator::clearMemory()
{
    sumInMemory = 0.0;
}

void Calculator::readMemory()
{

    m_display = QString::number(sumInMemory);
    emit displayChanged(m_display);
    waitingForOperand = true;
}

void Calculator::setMemory()
{
    equalClicked();
    sumInMemory = m_display.toDouble();
}

void Calculator::addToMemory()
{
    equalClicked();
    sumInMemory += m_display.toDouble();
}




void Calculator::abortOperation()
{
    clearAll();

    m_display = tr("####");
    emit displayChanged(m_display);
    QString::number(sumInMemory);
}


bool Calculator::calculate(double rightOperand, const Enum_Operations &pendingOperator)
{
    if (pendingOperator == Addition) {
        sumSoFar += rightOperand;
    } else if (pendingOperator == Subtraction) {
        sumSoFar -= rightOperand;
    } else if (pendingOperator == Multiplication) {
        factorSoFar *= rightOperand;
    } else if (pendingOperator == Division) {
        if (rightOperand == 0.0)
            return false;
        factorSoFar /= rightOperand;
    }
    return true;
}



// Copyright (c) 2019, Danilo Ferreira, Débora Bacelar and Willer Rodrigo.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <mms/Application.h>

#include <iostream>

MMS_NAMESPACE_BEGIN

Application::Application() {}
Application::~Application() {}

bool Application::inputBoolean(const std::string & status) const {
    std::cout << "Input: " << status << std::endl;

    bool value;
    std::cin >> value;

    return value;
}
float Application::inputFloat(const std::string & status) const {
    std::cout << "Input: " << status << std::endl;

    float value;
    std::cin >> value;

    return value;
}
void Application::output(const std::string & status) const {
    delay(cycles);
    std::cout << "Output: " << status << std::endl;
}
void Application::message(const std::string & status) const {
    delay(cycles);
    std::cout << "Message: " << status << std::endl;
}

void Application::delay(size_t cycles) const {
    size_t i = 0;
    while (i++ < cycles);
}

Application & Application::setCycles(size_t cycles) {
    this->cycles = cycles;
    return *this;
}
size_t Application::getCycles() const {
    return cycles;
}
Application & Application::setRunning(bool running) {
    this->running = running;
    return *this;
}
bool Application::isRunning() const {
    return running;
}

int Application::run() {
    setRunning(true);
    initialize();

    while (isRunning())
        execute();

    return 0;
}

MMS_NAMESPACE_END
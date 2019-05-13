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

#include <mms/MMS.h>

MMS_NAMESPACE_BEGIN

MMS::MMS() {}
MMS::~MMS() {}

MMS & MMS::initialize() {
    return *this;
}
MMS & MMS::execute() {
    message("INÍCIO DA ORDENHAÇÃO (UMA VACA)");
    milking();

    message("INÍCIO DA REFRIGERAÇÃO DO LEITE");
    refrigeration();

    message("INÍCIO DA LIMPEZA DOS EQUIPAMENTOS");
    cleanInPlace();

    return *this;
}

void MMS::milking() const {
    output("Abrir portão.");
    message("Aguardar entrada de uma vaca.");
    output("Fechar portão.");

    message("Verificando primeiros jatos de leite.");
    message("A vaca apresenta doença?");

    bool status = inputBoolean("0 - Não, 1 - Sim");

    if (status) {
        output("Abrir portão.");
        message("Aguardar retirada da vaca.");
        output("Fechar portão.");

        milking();
    }
    else {
        output("Ativar bomba de hipoclorito.");
        message("Aguardando lavagem dos testos a base de solução de hipoclorito de sódio.");
        output("Desativar bomba de hipoclorito.");

        message("Aguardando secagem e colocação das teteiras nos tetos (MANUAL).");
        output("Ativar teteiras de ordenha.");

        message("Aguardando finalização da ordenhação pelo sensor de vácuo:");

        while (!inputBoolean("0 - Ainda tem leite, 1 - Acabou o leite"))
            message("Ordenhando...");

        message("Ordenhação completa.");

        output("Desativar teteiras de ordenha.");

        output("Ativar bomba de iodo.");
        message("Aguardando lavagem dos tetos a base de solução de iodo.");
        output("Desativar bomba de iodo.");

        output("Abrir portão.");
        message("Aguardar retirada da vaca.");
        output("Fechar portão.");
    }
}
void MMS::refrigeration() const {
    output("Ativar bombeamento de leite para resfriador.");
    
    message("Aguardando finalização do bombeamento pelo sensor de nível:");

    while (!inputBoolean("0 - Enchendo, 1 - Cheio"))
        message("Bombeando...");

    message("Bombeamento completo.");

    output("Desativar bombeamento de leite.");
}
void MMS::cleanInPlace() const {
    milkingCIP();
    refrigerationCIP();
}
void MMS::milkingCIP() const {
    output("Ativar bombeamento de água morna nas tubulações da ordenha.");
    message("Aguardando enxágue...");
    output("Desativar bombeamento de água morna.");

    output("Ativar bombeamento de detergente alcalino clorado nas tubulações da ordenha.");
    message("Aguardando enxágue...");
    output("Desativar bombeamento de detergente alcalino clorado.");

    output("Ativar bombeamento de água morna.");
    message("Aguardando finalização de enxágue pelo sensor de Ph:");

    float ph;

    while ((ph = inputFloat("Finalização de enxágue, 6 <= Ph <= 8")) < 6 || ph > 8)
        message("Aguardando enxágue...");

    message("Limpeza completa.");

    output("Desativar bombeamento de água morna.");
}
void MMS::refrigerationCIP() const {
    output("Ativar drenagem de leite do refrigerador.");

    message("Aguardando finalização de drenagem pelo sensor de nível:");

    while (!inputBoolean("0 - Cheio, 1 - Vázio"))
        message("Drenando...");

    message("Drenagem completa.");

    output("Ativar bombeamento de hipoclorito de sódio no refrigerador.");

    message("Aguardando finalização do bombeamento pelo sensor de nível:");

    while (!inputBoolean("0 - Enchendo, 1 - Cheio"))
        message("Bombeando...");

    message("Bombeamento completo.");

    output("Desativar bombeamento de hipoclorito de sódio no refrigerador.");
    output("Ativar drenagem no refrigerador.");

    message("Aguardando finalização de drenagem pelo sensor de nível:");

    while (!inputBoolean("0 - Cheio, 1 - Vázio"))
        message("Drenando...");

    message("Drenagem completa.");

    output("Ativar bombeamento de água morna.");
    message("Aguardando finalização de enxágue pelo sensor de Ph:");

    float ph;

    while ((ph = inputFloat("Finalização de enxágue, 6 <= Ph <= 8")) < 6 || ph > 8)
        message("Aguardando enxágue...");

    message("Limpeza completa.");

    output("Desativar bombeamento de água morna.");
}

MMS_NAMESPACE_END
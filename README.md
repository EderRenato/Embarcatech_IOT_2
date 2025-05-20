# 📡 EMBARCATECH\_IOT – Estação Meteorológica IoT com Raspberry Pi Pico W

[![Google Drive](https://img.shields.io/badge/Demo-Google%20Drive-blue?logo=google-drive)](https://drive.google.com/file/d/1QK-6_EAmn_3b0Gt4GYG-eL51VC7XGTnt/view?usp=drive_link)

## 📝 Resumo

Sistema completo para monitoramento ambiental utilizando a Raspberry Pi Pico W com sensores de temperatura, umidade, luminosidade e detecção de chuva. Os dados são exibidos localmente em um display OLED e também disponibilizados via servidor web TCP no formato HTML e JSON.

## 📜 Descrição

Este projeto implementa uma mini estação meteorológica utilizando a **Raspberry Pi Pico W**, exibindo os dados em um **display OLED** e os disponibilizando via **servidor web embutido**. Os dados coletados incluem:

* 🌡️ Temperatura (sensor DHT22)
* 💧 Umidade relativa do ar (sensor DHT22)
* 💡 Luminosidade (sensor BH1750)
* 🌧️ Detecção de chuva com sensor digital

Todos os dados são acessíveis por uma **interface web moderna e responsiva**, bem como via **requisições HTTP** no formato **JSON** — sem qualquer dependência de servidores externos ou serviços em nuvem.

Também foi implementado alarmes visuais e sonoros para condições ambientais críticas

## 🧰 Componentes Utilizados

* Raspberry Pi Pico W
* Sensor DHT22 (Temperatura e Umidade)
* Sensor BH1750 (Luminosidade)
* Sensor de Chuva Digital
* Led RGB
* Buzzers
* Display OLED 128x64 (Driver SSD1306)
* Conexão Wi-Fi (via chip CYW43)
* Barramento I²C (dois canais independentes)

## 🧠 Funcionalidades

* Leitura periódica dos sensores (luminosidade a cada 2s, temperatura e umidade a cada 3s e chuva a cada 2s)
* Exibição em tela OLED (I²C)
* Servidor TCP (porta 80) com:
  * Atualização automática a cada 2.5s
  * Página HTML elegante e responsiva
  * Endpoint `/dados` para leitura de sensores via JSON
* Conexão automática à rede Wi-Fi
* Logs de requisições HTTP no console serial

## 📏 Parâmetros Críticos

<table>
  <tr>
    <th>Métrica</th>
    <th>Mínima</th>
    <th>Máxima</th>
  </tr>
  <tr>
    <td><strong>Temperatura</strong></td>
    <td>10°C</td>
    <td>35°C</td>
  </tr>
  <tr>
    <td><strong>Umidade</strong></td>
    <td>30%</td>
    <td>70%</td>
</table>

Quando qualquer valor excede os limites, o LED vermelho acende e o buzzer toca um alarme periódico (a cada 250 ms). Em caso de chuva, um alarme específico é disparado (a cada 600 ms).

## 🌐 Acesso Web

Após a conexão Wi-Fi ser estabelecida, o dispositivo imprime o endereço IP via serial.

Acesse pelo navegador:

* `http://<IP_DO_DISPOSITIVO>/` – Interface gráfica HTML
* `http://<IP_DO_DISPOSITIVO>/dados` – Resposta JSON:

```json
{
  "temperatura": 25.30,
  "umidade": 55.40,
  "luminosidade": 235.00,
  "chuva": false
}
```

## ⚙️ Estrutura do Código

```
.
├── Embarcatech_IOT.c               # Código principal
├── lib/
│   ├── lwipopts.h # Configurações para a internet
│   ├── font.h # Cabeçalho com as fontes para o display OLED
│   ├── ssd1306.c/h      # Driver para display OLED
│   ├── bh1750.c/h       # Driver do sensor de luminosidade
│   ├── buzzer.c/h       # Driver do buzzer
│   ├── rain_sensor.c/h       # Driver do sensor de chuva
│   └── dht22.c/h        # Leitura do sensor de temperatura/umidade
├── CMakeLists.txt       # Build system para a Raspberry Pi Pico
├── LICENSE
└── README.md            
```

## 📡 Wi-Fi

Configure seu SSID e senha no `main.c`:

```c
#define WIFI_SSID "SEU_WIFI"
#define WIFI_PASSWORD "SUA_SENHA"
```


## 🛠️ Compilação

Certifique-se de ter o SDK da Pico instalado. Compile com:

```bash
mkdir build
cd build
cmake ..
make
```

Grave o firmware na Pico W via UF2 ou `openocd`.


## 📖 Referências

* [Datasheet do DHT22](https://cdn.sparkfun.com/datasheets/Sensors/Temperature/DHT22.pdf)
* [Datasheet do BH1750](https://www.mouser.com/datasheet/2/348/bh1750fvi-e-186247.pdf)
* Pico SDK e exemplos oficiais da Raspberry Pi

## 🏛️ Licença

Este projeto está licenciado sob a Licença MIT. Você é livre para usar, modificar e distribuir o código, Todos os dados são acessíveis por uma interface web moderna e responsiva, bem como via requisições HTTP no formato JSON — sem qualquer dependência de servidores externos ou serviços em nuvem. Consulte o arquivo de licença para mais detalhes.

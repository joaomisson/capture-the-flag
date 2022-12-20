# Capture the Flag 🚩

![image](https://user-images.githubusercontent.com/50035537/208537656-7560cf95-8706-418c-aacb-99c54caa2e98.png)

Bem vindo ao jogo Capture the Flag! Este é nosso projeto final para a disciplina de **Sistemas Operacionais I** (SSC0140), do ICMC-USP. Neste trabalho, implementamos conceitos estudados na disciplina — mais especificamente, *threads* e semáforos — para criação de um jogo .


## Integrantes

| Nome                          | Número USP |
|-------------------------------|------------|
| Ana Lívia Ruegger Saldanha    | 8586691    |
| Guilherme Souza Panza         | 12543519   |
| João Antônio Misson Milhorim  | 11834331   |
| Maria Victória Brandão Barros | 12608692   |


## Descrição do jogo

**Capture the Flag** é um jogo competitivo para dois jogadores. O jogo possui 5 rodadas; a cada rodada, uma bandeira aparecere em um local aleatoria do campo. O objetivo dos jogadores deve ser pegar a bandeira antes do seu adversário; quem pegar a bandeira primeiro ganha uma rodada, e quem ganhar mais rodadas ganha o jogo.

As intruções detalhadas dos controles estão na tela inicial do jogo.


## Implementação: uso de threads e semáforos

No arquivo `game.cpp`, dentro da função `execute_round()`, criamos duas threads, uma para cada player; essas *threads* são criadas para termos duas sub-rotinas executando concomitantemente, ou seja, é como se as *threads* "competissem" para ter acesso a movimentação do seu respectivo player. Essa "competição" tem como objetivo criar uma mecânica para jogo e torná-lo mais divertido, já que, por meio dela, um player pode atrapalhar o jogo de seu inimigo, travando sua movimentação.

Utilizando-se dessa mecânica, implementamos também um "roubo" de movimentos, ou seja, enquanto um player estiver se movimentando, o outro pode "roubar" seu acesso à movimentação. Nesse cenário, as duas *threads* vão estar acessando uma região crítica de memória (uma variável de escopo global à qual ambas tem acesso). Dessa forma, no arquivo `game.cpp`, na função `get_current_player()`, utilizamos um semáforo binário especial (*mutex*), que trava o acesso simultâneo à variável global por ambas as *threads*, permitindo que apenas uma *thread* tenha acesso à variável de cada vez.

As implementações descritas acima estão destacadas por comentários no código.


## Instalação e execução

Para instalar/executar o jogo, clone este repositório ou baixe o .zip de todos os arquivos e extraia em um diretório vazio de seu computador.

Antes da primeira execução, será preciso instalar uma biblioteca que é utilizada no código, caso você ainda não a tenha instalada no seu computador. Para tal, digite o seguinte comando no seu terminal:

```
sudo apt-get install libncurses5-dev libncursesw5-dev
```

Finalmente, você poderá executar o jogo. No prompt de comando, certifique-se de que está no diretório no qual você clonou o projeto e utilize o seguinte comando para compilar e rodar o jogo:

```
make run
```

## Bom jogo!
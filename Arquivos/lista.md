# Lista de exercícios - Manipulação de Arquivos
## Exercício 1
Desenvolva um Programa que irá simular o tabuleiro do jogo Campo Minado. O tabuleiro deve ter 10x10 e seu valor padrão é de 0. Faça uma função que sorteie 10 posições aleatórias do tabuleiro e as preencha com o valor 1, que serão as minas. Por fim, exiba o tabuleiro na tela e salve esse tabuleiro em um arquivo "Tabuleiro.txt".
## Exercício 2
Desenvolva um Programa que irá simular uma partida do jogo Campo Minado. Use o arquivo gerado no exercício anterior para ser o tabuleiro. Faça o usuário informar a linha e a coluna que ele quer jogar, pesquise no arquivo essa posição e informe na tela o que ele acertou. Caso ele acerte a mina, o jogo termina. Caso acerte o campo, deve ser solicitado outra posição. Use a função fseek() para percorrer o arquivo.
## Exercício 3
Desenvolva um Programa que irá fazer relatórios quanto aos filmes que passam em um cinema. Crie um arquivo chamado "Sessao.txt" que deverá conter o nome do filme, o nome da sala e a duração da sessão em minutos. Serão dois relatórios: um para mostrar quais filmes se passam em uma determinada sala (usuário irá informar o nome da sala) e outro para mostrar em quais salas se passa um determinado filme (usuário irá informar o nome do filme). Use a função fseek() para percorrer o arquivo.
## Exercício 4
Desenvolva um Programa com uma Struct Aluno, contendo char Nome[40], char Ensino[30] e int RA. Salve 10 alunos em um arquivo binário. O Programa deverá solicitar ao usuário que digite a posicao do aluno, no arquivo, para pegar os dados desse. Então exiba os dados do Aluno na tela. Use a função fseek() para percorrer o arquivo.
## Exercício 5
Desenvolva um Programa com uma Struct Aluno, contendo int ID, char Nome[40], char Ensino[30], int RA e int IDMelhorAmigo. Salve 10 alunos em um arquivo binário. O Atributo ID, deve ser a posição do dado no arquivo. No atributo IDMelhorAmigo, você deve armazenar o número do ID de um colega (a posção dele no arquivo). O Programa deverá solicitar ao usuário que digite o RA do aluno. Então exiba os dados do Aluno na tela, sendo que deve ser exibido o nome do Melhor Amigo desse Aluno, baseado no IDMelhorAmigo, usando Fseek() para chegar a posição do dado.
## Exercício 6
Desenvolva um Programa em C que receba dois arquivos do usuário, e crie um terceiro arquivo com o conteúdo dos dois primeiros juntos (o conteúdo do primeiro seguido do conteúdo do segundo).

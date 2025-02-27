# Trabalho-ED
 Jogo de Uno de até 4 jogadores implementado em C

 O jogo uno consiste de 2 a 4, jogarem cartas no centro da mesa com cor ou número correspondente, o jogador que conseguir eliminar todas as cartas em sua mão primeiro vence.

Para usar o programa, os jogadores devem inserir a quantidade de jogadores. O jogo é iniciado com cada jogador recebendo 7 cartas.
Na primeira rodada o jogador 1 vê as cartas de sua mão e escolhe a carta da mesa, ele pode então escolher comprar uma carta, ou jogar uma carta.

A carta a ser escolhida será dita de acordo com sua ordem.

Após isso se torna rodada do jogador 2.

# Tabela para tradução:

cores<br>

azul		= A<br>
amarelo		= B<br>
verde		= C<br>
vermelho	= D<br>
cartas especiais (sem cor) = E<br>

## Formato da carta:

número cor

Exemplo:

2 B = carta número 2 de cor amarela

Números:

0 a 9<br>
10 - Comprar 2<br>
11 E - próximo jogador compra +4 cartas(próxima carta pode ser de qualquer cor)<br>
12 - Inverter<br>
13 - Pular jogador<br>
14 E - Troca a cor da carta da mesa(digitar a letra da cor escolhida)<br>


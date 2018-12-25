# Gerenciador de Cadastros de Matriculados
Um programa que permite organizar detalhadamente os matriculados em relação aos seus respectivos nomes, cursos, ano inicial de matricula e quantidade de matriculados.

https://github.com/LucasMMfernandes/Projetinho-AV2/blob/master/IMG1.png

O programa consta de dois parâmetros principais,são essas o nome do aluno e a matrícula do mesmo. Ao inserir corretamente os dois parâmetros, um série de detalhes aparecerão, e são esses se ele é um veterano, qual curso será cursado pelo aluno, e a relação de quantidade de alunos em cada curso.
O mais importante de tudo isso é chegar a pergunta de onde vem todas essas informações, e é bem simples, pois a matrícula de cada aluno possui essas informações. Neste programa a matrícula necessita de nove números, sendo os quatro primeiros o ano inicial de matrícula do aluno na instituição, sendo isto livre para o usuário colocar. O próximo número é o período do ano em que o aluno entrou, se dividindo apenas em período 1 e período 2, já que o programa não aceitará números diferentes desses. O sexto e o sétimo número combinados significam o curso em que estão matriculados, como pode ser visto na imagem, estão registrados dez cursos no programa, tendo cada um seus
rescpectivos números de referência:

Engenharia Elétrica = 01.
Administração = 02.
Computação = 03.
Automação Industrial = 04.
Contabilidade = 05.
Design de Interiores = 06.
Engenharia Civil = 07.
Telecomunicações = 08.
Geoprocessamento = 09.
Engenharia Química = 10.

https://github.com/LucasMMfernandes/Projetinho-AV2/blob/master/IMG2.png

Caso o número colocado também não esteja dentro da faixa mostrada, o programa mostrará a mensagem de matrícula inválida. E por último os dois últimos números são a posição na qual o estudante entrou no curso, sendo isto também de critério livre do usuário para colocar.
Caso o usuário deseje alterar alguma informação da tabela, so é preciso lembrar que o nome e a matrícula são codependetes, ou seja, caso deseje mudar o nome de um aluno, nas barras de inserir, repita a matrícula do mesmo aluno enquanto digita um nome diferente e clique no botão inserir. O mesmo ocorre para a situação contrária, caso deseje corrigir a matrícula de um aluno, repita o nome dele e digite a nova matrícula e, em seguida, clique no botão inserir, que assim todos os dados já serão automaticamente corrigidos.

Após entender como os parâmetros geram todas as informações, só resta apresentar as três diferentes formas de ordenação, e estas são:
Ordenação por Nome(na qual ordena os alunos em ordem alfabética).
Ordenação por Veterano(na  qual ordena através do ano de matrícula inicial do estudante).
Ordenação por Curso(este agrupa os alunos do mesmo curso juntos, mas neste caso os cursos não são em ordem alfabética, e sim na ordem de seus respectivos números, como mostrado anteriormente).
Lembrando também que é possível salvar e carregar arquivos que tenham seus parâmetros separados por vírgulas, para maior acessabilidade dos dados apresentados.

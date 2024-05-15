#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Estrutura para representar o grafo
struct Graph {
    int numVertices;
    bool **adjacencia;
};

// Função para criar um grafo com 'numVertices' vértices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjacencia = (bool**)malloc(numVertices * sizeof(bool*));

    for (int i = 0; i < numVertices; i++) {
        graph->adjacencia[i] = (bool*)malloc(numVertices * sizeof(bool));
        
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencia[i][j] = false;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjacencia[src][dest] = true;
}

void BFS(struct Graph* graph, int startVertex) {
    int fila[graph->numVertices];
    int inicio = 0, costa = 0;
    fila[costa++] = startVertex;

    bool visitado[graph->numVertices];
    for (int i = 0; i < graph->numVertices; i++) {
        visitado[i] = false;
    }
    visitado[startVertex] = true;

    printf("Resultado da BFS: \n");

    while (inicio < costa) {
        int currentVertex = fila[inicio++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjacencia[currentVertex][i] && !visitado[i]) {
                fila[costa++] = i;
                visitado[i] = true;
            }
        }
    }

    printf("\n");
}

void printGraph(struct Graph* graph) {
    printf("matriz Adjacencia :\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjacencia[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices;

    printf("Digite o número de vértices do grafo: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);

    int choice, src, dest;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Adicionar aresta\n");
        printf("2. Realizar Busca em Largura (BFS)\n");
        printf("3. Imprimir grafo\n");
        printf("4. Sair\n");
        printf("Digite a opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite o vértice de origem: ");
                scanf("%d", &src);
                printf("Digite o vértice de destino: ");
                scanf("%d", &dest);
                addEdge(graph, src, dest);
                break;
            case 2:
                printf("Digite o vértice de início da Busca em Largura (BFS): ");
                scanf("%d", &src);
                printf("Resultado da Busca em Largura (BFS) a partir do vértice %d:\n", src);
                BFS(graph, src);
                break;
            case 3:
                printGraph(graph);
                break;
            case 4:
                exit(0);
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}

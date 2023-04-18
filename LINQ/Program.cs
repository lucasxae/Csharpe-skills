using System;
using System.Collections.Generic;
using System.Linq;

namespace ExemplosLinq
{
    class Program
    {
        static void Main(string[] args)
        {
            // FONTE DE DADOS
            var listaProdutos = new List<Produto>()
            {
                new Produto {Id = 9, CategoriaId = 2, Name = "Geladeira", Status = true, Valor = 10},
                new Produto {Id = 2, CategoriaId = 3, Name = "Short", Status = true, Valor = 1},
                new Produto {Id = 4, CategoriaId = 1, Name = "Maquina de lavar", Status = false, Valor = 32},
                new Produto {Id = 3, CategoriaId = 1, Name = "Video Game", Status = true, Valor = 99},
                new Produto {Id = 6, CategoriaId = 2, Name = "Arroz", Status = true, Valor = 55},
                new Produto {Id = 8, CategoriaId = 1, Name = "TV", Status = true, Valor = 45},
                new Produto {Id = 1, CategoriaId = 3, Name = "Camiseta", Status = true, Valor = 100},
                new Produto {Id = 5, CategoriaId = 1, Name = "Microondas", Status = true, Valor = 90},
                new Produto {Id = 7, CategoriaId = 2, Name = "Feijão", Status = true, Valor = 12},
            };

        
            var listaCategorias = new List<Categoria>()
            {
                new Categoria { Id = 1, Status = true, Name = "Ëletronicos" },
                new Categoria { Id = 2, Status = true, Name = "Alimentos" },
                new Categoria { Id = 3, Status = true, Name = "Vestuario" }
            };


            // VALOR DA LISTA
            var ValorTotal = listaProdutos.Sum(prod => prod.Valor);

            // MEDIA DO VALOR DOS PRODUTOS
             var mediaValorProdutos = listaProdutos.Average(prod => prod.Valor);
            // QUANTOS ITENS TEM NA LISTA
            var contItensProdutos = listaProdutos.Count();
            var valorMaiorq90 = listaProdutos.Count(prod => prod.Valor > 90);
            //CRIAR UMA LISTA COM UM RANGE DE NUMEROS
            var range = Enumerable.Range(1, 15);

            foreach(var item in range)
            {
                Console.WriteLine(item);
            }
            // CRIAR UMA LISTA COM VARIOS ITENS SEMELHANTES
            var listaProdutosIguais = Enumerable.Repeat(new Produto() { Id = 1 }, 5);
            foreach (var item in listaProdutosIguais)
            {
                Console.WriteLine(item);
            }
            // CONSOLES
            Console.WriteLine($"Valor Total:  {ValorTotal}");
            Console.WriteLine($"Media:  {mediaValorProdutos}");
            Console.WriteLine($"Total de Itens:  {contItensProdutos}");
            Console.WriteLine($"Maior q 90:  {valorMaiorq90}");
        }
        class ProdutoResponse
        {
            public int Id { get; set; }
            public string Name { get; set; }
            public decimal Valor { get; set; }
        }
        class Produto
        {
            public int Id { get; set; }
            public string Name { get; set; }
            public bool Status { get; set; }
            public decimal Valor { get; set; }
            public int CategoriaId { get; set; }
            public List<Categoria> Categorias { get; set; }

        }

        class Categoria
        {
            public int Id { get; set; }
            public string Name { get; set; }
            public bool Status { get; set; }
        }

        class ProdutoDto
        {
            public string Name { get; set; }
            public decimal Valor { get; set; }
            public bool Status { get; set; }
        }
    }

}
// CRIAR CONSULTA LINQ
            
		//01 - filtrar produtos por nome
				
			var Results = from Produto in listaProdutos
                          where Produto.Name.ToLower() == "arroz".ToLower()
                          select Produto;

		// 02 - Filtrar prdotudos pela primeira letra do Nome

            var Results = from Produto in listaProdutos
                          where Produto.Name.ToLower().Substring(0, 1) == "m".ToLower()
                          select Produto;


		// 03 - Filtrar prdotudos pela primeira letra do Nome e status ativo

            var Results = from Produto in listaProdutos
                          where Produto.Name.ToLower().Substring(0, 1) == "m".ToLower() &&
                          Produto.Status == true
                          select Produto;


		//04 - ordenar os produtos por ID (orderby) descending => ordem decrescente
		
            var Results = from Produto in listaProdutos
                          where Produto.Id > 1 && Produto.Id < 6
                          orderby Produto.Id descending
                          select Produto;
						  
						  
						  
		//05 - Projetando dados com select
			
			var nameproduto = from prod in listaProdutos select prod.Name;

            var resultado = from prod in listaProdutos 
                            select new ProdutoDto 
                            { 
                                Name = prod.Name, 
                                Status = prod.Status,
                                Valor = prod.Valor + 10
                            };
						  
						  
						  
		//06 - Listando os itens por grupo	
            var results = from prod in listaProdutos
                          group prod by prod.Status into produtosAgrupados
                            select produtosAgrupados;


		// 07 -  buscar os produtos e informar o nome do produto e o nome da categoria do produto
            var result = from prod in listaProdutos
                         join cat in listaCategorias
                         on prod.CategoriaId equals cat.Id
                         select new
                         {
                             Produto = prod,
                             Categoria = cat
                         };
			  
						  
		// first = tras o primeiro item da lista
		// firtsOrDefault = se nao nn tiver item first ele retorna um default
            var resultado = listaProdutos.First( x => x.Id == 70);

            Console.WriteLine($"Nome: {resultado.Name} | {resultado.Id}");

            Console.ReadLine();
           
		
		// Last = tras o ultimo intem da lista 
		var resultado = listaProdutos.Last();

                Console.WriteLine($"Nome: {resultado.Name} | {resultado.Id}");

                Console.ReadLine();
						  
		
		var resultado = listaProdutos.LastOrDefault(x => x.Id == 70);

                Console.WriteLine($"Nome: {resultado.Name} | {resultado.Id}");

                Console.ReadLine();				  
						  
		// Single 
		var resultado = listaProdutos.SingleOrDefault(x => x.Id == 50);

                Console.WriteLine($"Nome: {resultado.Name} | {resultado.Id}");

                Console.ReadLine();
            
		// where
			var resultado = listaProdutos.Where(prod => prod.Id >= 2 && prod.Id <= 5);
		//order by  orderby descending
			resultado = resultado.OrderByDescending(prod => prod.Id);
		// revert
			resultado = resultado.Reverse();
	
		// select Many


            var listaCategoria = listaProdutos.SelectMany(prod => prod.Categorias);
			
			// e igual a:

            //var listaCategoria = new List<Categoria>();

            //foreach (var prod in listaProdutos )
            //{
            //    foreach(var cat in prod.Categorias)
            //    {
            //        listaCategoria.Add(new Categoria()
            //        {
            //            Id= cat.Id, Name = cat.Name, Status = cat.Status
            //        });
            //    }
            //}


			// TAKE AND SKIP 
			
			 // ignorar os 3 primeiros produtos e pegar o restante
            var tresPrimeiros = listaProdutos.Take(3);
            // pegar os 3 primeiros produtos e ignorar o restante
            var ignorarTresPrimeiros = listaProdutos.Skip(3);
            // ignorar os 3 primeiros e pegar os proximos 3 e ignorar o restante
            var resultado = listaProdutos.Skip(3).Take(3);
           
            Console.WriteLine("----------- TRES PRIMEIROS ------------");
            foreach ( var prod in tresPrimeiros)
            {
                Console.WriteLine($"Id: {prod.Id} | Nome: {prod.Name}");
            }

            Console.WriteLine("----------- SKIP TRES PRIMEIROS ------------");
            foreach (var prod in ignorarTresPrimeiros)
            {
                Console.WriteLine($"Id: {prod.Id} | Nome: {prod.Name}");
            }

            Console.WriteLine("----------- TRES DO MEIO ------------");
            foreach (var prod in resultado)
            {
                Console.WriteLine($"Id: {prod.Id} | Nome: {prod.Name}");
            }









		//.ToLower = transforma tudo de maiusculo pra minusculo 
		// .Substring(qual posicao comecar[0], quantos caracteres dps do inicio[1])
			
	
			
			
            

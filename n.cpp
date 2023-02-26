/**************************
* Лабараторная работа № 3 *
***************************/
using System;
namespace MatrixAB
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Размерность Квадратной Матрицы: ");
            int Size = int.Parse(Console.ReadLine());
            MatrixInf MatrixA = new MatrixFound(Size);
            MatrixInf MatrixB = new MatrixFound(Size);
            MatrixA.Produce();
            MatrixB.Produce();
            Console.WriteLine(MatrixA.ToString());
            Console.WriteLine(MatrixB.ToString());

            Console.WriteLine("\nМеню:: ");
            Console.WriteLine("1. Сложение\n2. Вычитание\n3. Умножение\n4. Деление\n5. Равно\n6. Сравнение >\n7. Сравнение <\n8. Сравнение >=\n" 
                " 9. Сравнение <=\n10. Найти Определитель\n11. Обратная матрица\n");
            string choice = Console.ReadLine();
            switch (choice) 
            {
                case "1":
                    Console.WriteLine($"MatrixA + MatrixB \n{MatrixA + MatrixB}");
                    break;
                case "2":
                    Console.WriteLine($"MatrixA - MatrixB \n{MatrixA - MatrixB}");
                    break;
                case "3":
                    Console.WriteLine($"MatrixA * MatrixB \n{MatrixA * MatrixB}");
                    break;
                case "4":
                    Console.WriteLine($"MatrixA / MatrixB \n{MatrixA / MatrixB}");
                    break;
                case "5":
                    Console.WriteLine($"MatrixA == MatrixB: {MatrixA == MatrixB}");
                    break;
                case "6":
                    Console.WriteLine($"MatrixA > MatrixB: {MatrixA > MatrixB}");
                    break;
                case "7":
                    Console.WriteLine($"MatrixA < MatrixB: {MatrixA < MatrixB}");
                    break;
                case "8":
                    Console.WriteLine($"MatrixA >= MatrixB: {MatrixA >= MatrixB}");
                    break;
                case "9":
                    Console.WriteLine($"MatrixA <= MatrixB: {MatrixA <= MatrixB}");
                    break;
                case "10":
                    Console.WriteLine($"Determinant of MatrixA: {MatrixA.Determ(MatrixA)}");
                    break;
                case "11":
                    try
                    {
                        var inverseA = MatrixA.Inverse(MatrixA);
                        Console.WriteLine($"Инверсия Матрицы:\n{inverseA}");
                    }
                    catch (NotInvertibleMatrix ex)
                    {
                        Console.WriteLine("Матрица не имеет инверсии");
                    }
                    break;
                default:
                    Console.WriteLine("Неправильный ввод");
                    break;
            }
            Console.ReadKey();
        }
    }
}

/**************************
* Лабараторная работа № 3 *
***************************/
using System;
namespace SquareMatrix
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Размер квадратной матрицы: ");
            int Size = int.Parse(Console.ReadLine());
            MatrixInf MatrixOne = new MatrixFound(Size);
            MatrixInf MatrixTwo = new MatrixFound(Size);
            MatrixA.Produce();
            MatrixB.Produce();
            Console.WriteLine(MatrixOne.ToString());
            Console.WriteLine(MatrixTwo.ToString());

            Console.WriteLine("\nМеню: ");
            Console.WriteLine("1. Сложение +\n2. Вычитание -\n3. Умножение *\n4. Деление /\n5. Равно =\n6. Сравнение(больше) >\n7. Сравнение(меньше) <\n" 
                "8. Сравнение (больше равно) >=\n 9. Сравнение (меньше равно) <=\n10. Найти Определитель\n11. Обратная матрица\n");
            string choice = Console.ReadLine();
            switch (choice) 
            {
                case "1":
                    Console.WriteLine($"MatrixOne + MatrixTwo \n{MatrixOne + MatrixTwo}");
                    break;
                case "2":
                    Console.WriteLine($"MatrixOne - MatrixTwo \n{MatrixOne - MatrixTwo}");
                    break;
                case "3":
                    Console.WriteLine($"MatrixOne * MatrixTwo \n{MatrixOne * MatrixTwo}");
                    break;
                case "4":
                    Console.WriteLine($"MatrixOne / MatrixTwo \n{MatrixOne / MatrixTwo}");
                    break;
                case "5":
                    Console.WriteLine($"MatrixOne == MatrixTwo: {MatrixOne == MatrixTwo}");
                    break;
                case "6":
                    Console.WriteLine($"MatrixOne > MatrixTwo: {MatrixOne > MatrixTwo}");
                    break;
                case "7":
                    Console.WriteLine($"MatriOnexOne < MatrixTwo: {MatrixOne < MatrixTwo}");
                    break;
                case "8":
                    Console.WriteLine($"MatrixOne >= MatrixTwo: {MatrixOne >= MatrixTwo}");
                    break;
                case "9":
                    Console.WriteLine($"MatrixOne <= MatrixTwo: {MatrixOne <= MatrixTwo}");
                    break;
                case "10":
                    Console.WriteLine($"Determinant of MatrixOne: {MatrixOne.Determ(MatrixOne)}");
                    break;
                case "11":
                    try
                    {
                        var inverseOne = MatrixOne.Inverse(MatrixOne);
                        Console.WriteLine($"Инверсия Матрицы:\n{inverseOne}");
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

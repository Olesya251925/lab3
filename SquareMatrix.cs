using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Linq;
using System.Text;

namespace Lab3
{
    public class SquareMatrix
    {
        public int Size;
        public int[,] Matrix;
        Random ValRandom = new Random(Guid.NewGuid().GetHashCode());
        public SquareMatrix(int Size)
        {
            this.Size = Size;
            Matrix = new int[Size, Size];
            for (int ColumnIndex = 0; ColumnIndex < Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < Size; ++RowIndex)
                {
                    Matrix[ColumnIndex, RowIndex] = ValRandom.Next(10);
                    if (Matrix[ColumnIndex, RowIndex] < 0)
                    {
                        throw new NegativeElement("Матрица содержит отрицательные числа!");
                    }
                }
            }
        }
        public SquareMatrix()
        {

        }
        public class NegativeElement : Exception
        {
            public NegativeElement(string message) : base(message)
            {
            }
        }

        public void PrintMatrix()
        {
            for (int ColumnIndex = 0; ColumnIndex < Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < Size; ++RowIndex)
                {
                    Console.Write(Matrix[ColumnIndex, RowIndex] + " ");
                }
                Console.WriteLine(" ");
            }
        }

        public static SquareMatrix operator +(SquareMatrix LeftMatrix, SquareMatrix RightMatrix)
        {
            SquareMatrix Result = new SquareMatrix(LeftMatrix.Size);

            for (int ColumnIndex = 0; ColumnIndex < Result.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < Result.Size; ++RowIndex)
                {
                    Result.Matrix[ColumnIndex, RowIndex] = LeftMatrix.Matrix[ColumnIndex, RowIndex] + RightMatrix.Matrix[ColumnIndex, RowIndex];
                }
            }

            return Result;
        }

        public static int operator -(SquareMatrix LeftMatrix, SquareMatrix RightMatrix)
        {
            int Result;
            int SumLeftMatrix = 0;
            int SumRightMatrix = 0;

            for (int ColumnIndex = 0; ColumnIndex < LeftMatrix.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < LeftMatrix.Size; ++RowIndex)
                {
                    SumLeftMatrix = SumLeftMatrix + LeftMatrix.Matrix[ColumnIndex, RowIndex];

                }
            }

            for (int ColumnIndex = 0; ColumnIndex < RightMatrix.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < RightMatrix.Size; ++RowIndex)
                {
                    SumRightMatrix = SumRightMatrix + RightMatrix.Matrix[ColumnIndex, RowIndex];

                }
            }

            Result = SumLeftMatrix - SumRightMatrix;

            return Result;
        }

        public static SquareMatrix operator *(SquareMatrix LeftMatrix, SquareMatrix RightMatrix)
        {
            SquareMatrix Result = new SquareMatrix(LeftMatrix.Size);

            for (int ColumnIndex = 0; ColumnIndex < Result.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < Result.Size; ++RowIndex)
                {
                    Result.Matrix[ColumnIndex, RowIndex] = LeftMatrix.Matrix[ColumnIndex, RowIndex] * RightMatrix.Matrix[ColumnIndex, RowIndex];
                }
            }

            return Result;
        }

        public static bool operator <(SquareMatrix LeftMatrix, SquareMatrix RightMatrix)
        {
            int SumLeftMatrix = 0;
            int SumRightMatrix = 0;

            for (int ColumnIndex = 0; ColumnIndex < LeftMatrix.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < LeftMatrix.Size; ++RowIndex)
                {
                    SumLeftMatrix = SumLeftMatrix + LeftMatrix.Matrix[ColumnIndex, RowIndex];

                }
            }

            for (int ColumnIndex = 0; ColumnIndex < RightMatrix.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < RightMatrix.Size; ++RowIndex)
                {
                    SumRightMatrix = SumRightMatrix + RightMatrix.Matrix[ColumnIndex, RowIndex];

                }
            }

            return (SumLeftMatrix < SumRightMatrix);
        }

        public static bool operator >(SquareMatrix LeftMatrix, SquareMatrix RightMatrix)
        {
            int SumLeftMatrix = 0;
            int SumRightMatrix = 0;

            for (int ColumnIndex = 0; ColumnIndex < LeftMatrix.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < LeftMatrix.Size; ++RowIndex)
                {
                    SumLeftMatrix = SumLeftMatrix + LeftMatrix.Matrix[ColumnIndex, RowIndex];

                }
            }

            for (int ColumnIndex = 0; ColumnIndex < RightMatrix.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < RightMatrix.Size; ++RowIndex)
                {
                    SumRightMatrix = SumRightMatrix + RightMatrix.Matrix[ColumnIndex, RowIndex];

                }
            }

            return (SumLeftMatrix > SumRightMatrix);
        }

        public static bool operator <=(SquareMatrix LeftMatrix, SquareMatrix RightMatrix)
        {
            int SumLeftMatrix = 0;
            int SumRightMatrix = 0;

            for (int ColumnIndex = 0; ColumnIndex < LeftMatrix.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < LeftMatrix.Size; ++RowIndex)
                {
                    SumLeftMatrix = SumLeftMatrix + LeftMatrix.Matrix[ColumnIndex, RowIndex];

                }
            }

            for (int ColumnIndex = 0; ColumnIndex < RightMatrix.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < RightMatrix.Size; ++RowIndex)
                {
                    SumRightMatrix = SumRightMatrix + RightMatrix.Matrix[ColumnIndex, RowIndex];

                }
            }

            return (SumLeftMatrix <= SumRightMatrix);
        }

        public static bool operator >=(SquareMatrix LeftMatrix, SquareMatrix RightMatrix)
        {
            int SumLeftMatrix = 0;
            int SumRightMatrix = 0;

            for (int ColumnIndex = 0; ColumnIndex < LeftMatrix.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < LeftMatrix.Size; ++RowIndex)
                {
                    SumLeftMatrix = SumLeftMatrix + LeftMatrix.Matrix[ColumnIndex, RowIndex];

                }
            }

            for (int ColumnIndex = 0; ColumnIndex < RightMatrix.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < RightMatrix.Size; ++RowIndex)
                {
                    SumRightMatrix = SumRightMatrix + RightMatrix.Matrix[ColumnIndex, RowIndex];

                }
            }

            return (SumLeftMatrix >= SumRightMatrix);
        }

        public static bool operator ==(SquareMatrix LeftMatrix, SquareMatrix RightMatrix)
        {
            int SumLeftMatrix = 0;
            int SumRightMatrix = 0;

            for (int ColumnIndex = 0; ColumnIndex < LeftMatrix.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < LeftMatrix.Size; ++RowIndex)
                {
                    SumLeftMatrix = SumLeftMatrix + LeftMatrix.Matrix[ColumnIndex, RowIndex];

                }
            }

            for (int ColumnIndex = 0; ColumnIndex < RightMatrix.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < RightMatrix.Size; ++RowIndex)
                {
                    SumRightMatrix = SumRightMatrix + RightMatrix.Matrix[ColumnIndex, RowIndex];

                }
            }

            return (SumLeftMatrix == SumRightMatrix);
        }

        public static bool operator !=(SquareMatrix LeftMatrix, SquareMatrix RightMatrix)
        {
            int SumLeftMatrix = 0;
            int SumRightMatrix = 0;

            for (int ColumnIndex = 0; ColumnIndex < LeftMatrix.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < LeftMatrix.Size; ++RowIndex)
                {
                    SumLeftMatrix = SumLeftMatrix + LeftMatrix.Matrix[ColumnIndex, RowIndex];

                }
            }

            for (int ColumnIndex = 0; ColumnIndex < RightMatrix.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < RightMatrix.Size; ++RowIndex)
                {
                    SumRightMatrix = SumRightMatrix + RightMatrix.Matrix[ColumnIndex, RowIndex];

                }
            }

            return (SumLeftMatrix != SumRightMatrix);
        }
        public static bool operator true(SquareMatrix Matrix)
        {
            for (int RowIndex = 0; RowIndex < Matrix.Size; ++RowIndex)
            {
                for (int ColumnIndex = 0; ColumnIndex < Matrix.Size; ++ColumnIndex)
                {
                    if (Matrix.Matrix[RowIndex, ColumnIndex] == 0);
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        public static bool operator false(SquareMatrix Matrix)
        {
            for (int RowIndex = 0; RowIndex < Matrix.Size; ++RowIndex)
            {
                for (int ColumnIndex = 0; ColumnIndex < Matrix.Size; ++ColumnIndex)
                {
                    if (Matrix.Matrix[RowIndex, ColumnIndex] != 0);
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        public static int Determinant(SquareMatrix Matrix)
        {
            int SummMatrix = 0;
            int CountElements = 0;
            int Determinant;
            for (int RowIndex = 0; RowIndex < Matrix.Size; ++RowIndex)
            {
                for (int ColumnIndex = 0; ColumnIndex < Matrix.Size; ++ColumnIndex)
                {
                    SummMatrix += Matrix.Matrix[RowIndex, ColumnIndex];
                    ++CountElements;
                }
            }
            Determinant = SummMatrix / CountElements;

            return Determinant;
        }

        public static SquareMatrix Inverse(SquareMatrix Matrix)
        {
            SquareMatrix InverseMatix = new SquareMatrix(Matrix.Size);
            for (int RowIndex = 0; RowIndex < Matrix.Size; ++RowIndex)
            {
                for (int ColumnIndex = 0; ColumnIndex < Matrix.Size; ++ColumnIndex)
                {
                    InverseMatix.Matrix[RowIndex, ColumnIndex] = Matrix.Matrix[RowIndex, ColumnIndex] * -1;
                }
            }
            return InverseMatix;
        }

        public override string ToString()
        {
            string MatrixString = "";

            for (int RowIndex = 0; RowIndex < Size; ++RowIndex)
            {
                for (int ColumnIndex = 0; ColumnIndex < Size; ++ColumnIndex)
                {
                    MatrixString += Matrix[RowIndex, ColumnIndex].ToString() + "\t";
                }
                MatrixString += "\n";
            }

            return MatrixString;
        }

        public static int CompareTo(SquareMatrix LeftMatrix, SquareMatrix RightMatrix)
        {
            int SumLeftMatrix = 0;
            int SumRightMatrix = 0;

            for (int ColumnIndex = 0; ColumnIndex < LeftMatrix.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < LeftMatrix.Size; ++RowIndex)
                {
                    SumLeftMatrix = SumLeftMatrix + LeftMatrix.Matrix[ColumnIndex, RowIndex];

                }
            }

            for (int ColumnIndex = 0; ColumnIndex < RightMatrix.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < RightMatrix.Size; ++RowIndex)
                {
                    SumRightMatrix = SumRightMatrix + RightMatrix.Matrix[ColumnIndex, RowIndex];

                }
            }

            if (SumLeftMatrix > SumRightMatrix)
            {
                return 1;
            }
            else if (SumLeftMatrix == SumRightMatrix)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }

        public bool Equals(SquareMatrix EqualsMatrix)
        {
            for (int RowIndex = 0; RowIndex < Size; ++RowIndex)
            {
                for (int ColumnIndex = 0; ColumnIndex < Size; ++ColumnIndex)
                {
                    if (Matrix[RowIndex, ColumnIndex] != EqualsMatrix.Matrix[RowIndex, ColumnIndex])
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        public override int GetHashCode()
        {
            return Matrix.GetHashCode();
        }
    }

}

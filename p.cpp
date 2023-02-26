using System;
namespace MatrixAB
{
    class MatrixFound
    {
        private int Size;
        private double[,] Arry;

        public MatrixFound() { }
        public int SizeN
        {
            get { return Size; }
            set { if (value < 0) Size = value; }

        }
        public MatrixFound(int Size)
        {
            this.Size = Size;
            Arry = new double[this.Size, this.Size];
        }
        public double this[int ColumnCount, int RowCount]
        {
            get
            {
                return Arry[ColumnCount, RowCount];
            }
            set
            {
                Arry[ColumnCount, RowCount] = value;
            }
        }

        public void Produce()
        {
           Arry = new double[Size, Size];
            var RandomNumber = new Random((int)Stopwatch.GetTimestamp());
            for (int ColumnIndex = 0; ColumnIndex < Size; ++ColumnIndex)
            {
                for (int RowIndex  = 0; RowIndex  < Size; ++RowIndex )
                {
                    Arry[ColumnIndex, RowIndex ] = RandomNumber.Next(10, 100);
                }
            }
        }
        public MatrixFound DeepCopy()
        {
           MatrixFound clone = (MatrixFound)this.MemberwiseClone();
           return clone;
        }

        public int CompareTo(MatrixFound other)
        {
            if (other is null)
                return 1;

            if (Size != other.Size)
                return Size.CompareTo(other.Size);

            for (int ColumnIndex = 0; ColumnIndex < Size; ++ColumnIndex)
            {
                for (int RowIndex  = 0; RowIndex < Size; ++RowIndex )
                {
                    int compare = Arry[ColumnIndex, RowIndex ].CompareTo(other.Arry[ColumnIndex, RowIndex ]);
                    if (compare != 0)
                        return compare;
                }
            }
            return 0;
        }
        public override bool Equals(object obj)
        {
            if (obj is null || !(obj is MatrixFound))
            {
                return false;
            }
            return this == (MatrixFound)obj;
        }
        public override int GetHashCode()
        { 
            unchecked
            {
                int hashCode = 20;
                for (int ColumnCounter = 0; ColumnCounter < Size; ++ColumnCounter)
                {
                    for (int RowCounter = 0; RowCounter < Size; ++RowCounter)
                    {
                        hashCode = hashCode * 23 + Arry[ColumnCounter, RowCounter].GetHashCode();
                    }
                }
                return hashCode;
            }
        }
        //Сложение
        public static MatrixFound operator +(MatrixFound A, MatrixFound B) 
        {
            var Result = new MatrixFound(A.SizeN);
            for (int ColumnIndex = 0; ColumnIndex < Result.SizeN; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < Result.SizeN; ++RowIndex)
                {
                    Result[ColumnIndex, RowIndex] = A[ColumnIndex, RowIndex] + B[ColumnIndex, RowIndex];
                }
            }
            return Result;
        }
        //Вычитание
        public static MatrixFound operator -(MatrixFound A, MatrixFound B)
        {
            var Result = new MatrixFound(A.SizeN);
            for (int ColumnIndex = 0; ColumnIndex < Result.SizeN; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < Result.SizeN; ++RowIndex)
                {
                    Result[ColumnIndex, RowIndex] = A[ColumnIndex, RowIndex] - B[ColumnIndex, RowIndex];
                }
            }
            return Result;
        }
        //Умножение 
        public static MatrixFound operator *(MatrixFound A,MatrixFound B)
        {
            var Result = new MatrixFound(A.SizeN);
            for (int ColumnIndex = 0; ColumnIndex < Result.SizeN; ++ColumnIndex)
            {
                for (int K = 0; K < A.SizeN; ++K)
                {
                    for (int RowIndex = 0; RowIndex < Result.SizeN; ++RowIndex)
                    {
                        Result[ColumnIndex, K] += A[RowIndex, K] * B[ColumnIndex, RowIndex];
                    }
                }
            }
            return Result;
        }
        //Деление
        public static MatrixFound operator /(MatrixFound A, MatrixFound B)
        {
            var Result = new MatrixFound(A.SizeN);
            for (int ColumnIndex = 0; ColumnIndex < Result.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < Result.SizeN; ++RowIndex)
                {
                    try
                    {
                        Result[ColumnIndex, RowIndex] = A[ColumnIndex,RowIndex] / B[ColumnIndex, RowIndex];
                    }
                    catch 
                    {
                        Result[ColumnIndex, RowIndex] = 0;
                    }
                }
            }
            return Result;
        }
        //Операторы сравнения
        public static bool operator ==(MatrixFound A,MatrixFound B)
        {
            if (A.SizeN != B.SizeN)
            {
                return true;
            }
            for (int ColumnIndex = 0; ColumnIndex < A.SizeN; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < A.SizeN; ++RowIndex)
                {
                    if (A[ColumnIndex, RowIndex] == B[ColumnIndex, RowIndex])
                    {
                        return true;
                    }
                }

            }
            return false;
        }
        public static bool operator !=(MatrixFound A, MatrixFound B)
        {
            if (A.SizeN != B.SizeN)
            {
                return true;
            }
            for (int ColumnIndex = 0; ColumnIndex < A.SizeN; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < A.SizeN; ++RowIndex)
                {
                    if (A[ColumnIndex, RowIndex != B[ColumnIndex, RowIndex])
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        public static MatrixFound operator >(MatrixFound A, MatrixFound B)
        {
            var Result = new MatrixFound(A.SizeN);
            for (int ColumnIndex = 0; ColumnIndex < Result.SizeN; ++ColumnIndex)
            {
                for (int RowIndex = 0;RowIndex < Result.SizeN; ++RowIndex)
                {
                    if (A[ColumnIndex,RowIndex] > B[ColumnIndex, RowIndex])
                    {
                        Result[ColumnIndex, RowIndex] = 1;
                    }
                    else
                    {
                        Result[ColumnIndex, RowIndex] = 0;
                    }
                }
            }
            return Result;
        }
        public static MatrixFound operator <(MatrixFound A,MatrixFound B)
        {
            var Result = new MatrixFound(A.SizeN);
            for (int ColumnIndex = 0; ColumnIndex < Result.SizeN; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < Result.SizeN; ++RowIndex)
                {
                    if (A[ColumnIndex, RowIndex] < B[ColumnIndex, RowIndex])
                    {
                        Result[ColumnIndex,RowIndex] = 1;
                    }
                    else
                    {
                        Result[ColumnIndex, IndexRow] = 0;
                    }
                }
            }
            return Result;
        }

        public static MatrixFound operator >=(MatrixFound A, MatrixFound B)
        {
            var Result = new MatrixFound(A.SizeN);
            for (int ColumnIndex = 0; ColumnIndex < Result.SizeN; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < Result.SizeN; ++RowIndex)
                {
                    if (A[ColumnIndex, RowIndex] >= B[ColumnIndex,RowIndex])
                    {
                        Result[ColumnIndex, RowIndex] = 1;
                    }
                    else
                    {
                        Result[ColumnIndex, RowIndex] = 0;
                    }
                }
            }
            return Result;

        }
        public static MatrixFound operator <=(MatrixFound A, MatrixFound B)
        {
            var Result = newMatrixFound(A.SizeN);
            for (int ColumnIndex = 0; ColumnIndex < Result.SizeN; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < Result.SizeN; ++RowIndex)
                {
                    if (A[ColumnIndex, RowIndex] <= B[ColumnIndex, RowIndex])
                    {
                        Result[ColumnIndex, RowIndex] = 1;
                    }
                    else
                    {
                        Result[ColumnIndex, RowIndex] = 0;
                    }
                }
            }
            return Result;
        }
        //Поиск Минора и по нему находим определитель. 
        public static MatrixFound Minor(MatrixFound A, int Column, int Row)
        {
           MatrixFound buf = new MatrixFound(A.SizeN - 1);
            for (int ColumnIndex = 0; ColumnIndex < A.SizeN; ++ColumnIndex) 
            { 
                for (int RowIndex = 0;RowIndex < A.SizeN; ++RowIndex) 
                {
                    if((RowIndex != Row) || (ColumnIndex != Column))
                    {
                        if (ColumnIndex > Column && RowIndex < Row) buf[ColumnIndex - 1,RowIndex] = A[ColumnIndex, RowIndex];
                        if (ColumnIndex < Column && RowIndex > Row) buf[ColumnIndex, RowIndex - 1] = A[ColumnIndex, RowIndex];
                        if (ColumnIndex > Column && RowIndex > Row) buf[ColumnIndex - 1, RowIndex - 1] = A[ColumnIndex, RowIndex];
                        if (ColumnIndex < Column && RowIndex < Row) buf[ColumnIndex, RowIndex] = A[ColumnIndex, RowIndex];
                    }
                }
            }
            return buf;
        }
        public double Determ(MatrixInf A)
        {
            double det = 0;
            int Rank = A.SizeN;
            if (Rank == 1) det = A[0, 0];
            if (Rank == 2) det = A[0, 0] * A[1, 1] - A[0, 1] * A[1, 0];
            if (Rank > 2)
            {
                for (int Index = 0; Index < A.SizeN; ++Index) 
                {
                    det += Math.Pow(-1, 0 + Index) * A[0, Index] * Determ(Minor( A, 0, Index));
                }
            }
            return det;
        }

        private MatrixFound SubMatrix(int Row, int Column)
        {
            var subMatrix = new MatrixFound(Size - 1);

            int subRow = 0;
            for (int RowIndex = 0; RowIndex < Size; ++RowIndex)
            {
                if (RowIndex == Row)
                    continue;
                int subColumn = 0;
                for (int ColumnIndex = 0; ColumnIndex < Size; ++ColumnIndex) 
                { 
                    if (ColumnIndex == Column)
                        continue;

                    subMatrix[subColumn, subColumn] = Arry[ColumnIndex, ColumnIndex];
                    ++subColumn;
                }
                ++subRow;
            }
            return subMatrix;
        }

        public MatrixFound Inverse(MatrixFound A)
        {
            var Determinant = Determ(A);
            if (Determinant == 0)
            {
                throw new InvalidOperationException("Матрица не имеет инверсии");
            }
            var Result = new MatrixFound(A.SizeN);

            int sign = 1;
            for (int ColumnIndex = 0; ColumnIndex < Result.SizeN; ColumnIndex++)
            {
                for (int RowIndex = 0; RowIndex < Result.SizeN; RowIndex++)
                {
                    var subMatrix = SubMatrix(ColumnIndex, RowIndex);
                    Result[RowIndex, ColumnIndex] = sign * subMatrix.Determ(A) / Determinant;
                    sign = -sign;
                }
            }

            return Result;
        }

        public override string ToString()
        {
            string Result = $"Размеры: {Size} x {Size}\n";
            Result += "\n Матрица\n";
            for (int ColumnIndex = 0; ColumnIndex < Size; ++ColumnIndex)
            {
                for (int RowIndex = 0;RowIndex < Size; ++RowIndex)
                {
                    Result += Arry[ColumnIndex, RowIndex].ToString() + "\t";
                }
                Result += "\n";
            }
            return Result ;

        }
    }
}

using System;
namespace SquareMatrix
{
    class MatrixFound
    {
        private int Size;
        private double[] Arry;

        public MatrixFound() { }
        public int SizeN
        {
            get { return Size; }
            set { if (Number < 0) Size = Number; }

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
                Arry[ColumnCount, RowCount] = Number;
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
        public MatrixFound Copy()
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
                int HashCode = 10;
                for (int ColumnCounter = 0; ColumnCounter < Size; ++ColumnCounter)
                {
                    for (int RowCounter = 0; RowCounter < Size; ++RowCounter)
                    {
                        HashCode = HashCode * 13 + Arry[ColumnCounter, RowCounter].GetHashCode();
                    }
                }
                return HashCode;
            }
        }
        public static MatrixFound operator +(MatrixFound One, MatrixFound Two) 
        {
            var Result = new MatrixFound(One.SizeN);
            for (int ColumnIndex = 0; ColumnIndex < Result.SizeN; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < Result.SizeN; ++RowIndex)
                {
                    Result[ColumnIndex, RowIndex] = A[ColumnIndex, RowIndex] + B[ColumnIndex, RowIndex];
                }
            }
            return Result;
        }
        public static MatrixFound operator -(MatrixFound One, MatrixFound Two)
        {
            var Result = new MatrixFound(A.SizeN);
            for (int ColumnIndex = 0; ColumnIndex < Result.SizeN; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < Result.SizeN; ++RowIndex)
                {
                    Result[ColumnIndex, RowIndex] = One[ColumnIndex, RowIndex] - Two[ColumnIndex, RowIndex];
                }
            }
            return Result;
        } 
        public static MatrixFound operator *(MatrixFound One, MatrixFound Two)
        {
            var Result = new MatrixFound(A.SizeN);
            for (int ColumnIndex = 0; ColumnIndex < Result.SizeN; ++ColumnIndex)
            {
                for (int K = 0; K < A.SizeN; ++K)
                {
                    for (int RowIndex = 0; RowIndex < Result.SizeN; ++RowIndex)
                    {
                        Result[ColumnIndex, K] += One[RowIndex, K] * Two[ColumnIndex, RowIndex];
                    }
                }
            }
            return Result;
        }
        public static MatrixFound operator /(MatrixFound One, MatrixFound Two)
        {
            var Result = new MatrixFound(A.SizeN);
            for (int ColumnIndex = 0; ColumnIndex < Result.Size; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < Result.SizeN; ++RowIndex)
                {
                    try
                    {
                        Result[ColumnIndex, RowIndex] = One[ColumnIndex,RowIndex] / Two[ColumnIndex, RowIndex];
                    }
                    catch 
                    {
                        Result[ColumnIndex, RowIndex] = 0;
                    }
                }
            }
            return Result;
        }
        public static bool operator ==(MatrixFound One,MatrixFound Two)
        {
            if (A.SizeN != B.SizeN)
            {
                return true;
            }
            for (int ColumnIndex = 0; ColumnIndex < One.SizeN; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < One.SizeN; ++RowIndex)
                {
                    if (One[ColumnIndex, RowIndex] == Two[ColumnIndex, RowIndex])
                    {
                        return true;
                    }
                }

            }
            return false;
        }
        public static bool operator !=(MatrixFound One, MatrixFound Two)
        {
            if (One.SizeN != Two.SizeN)
            {
                return true;
            }
            for (int ColumnIndex = 0; ColumnIndex < One.SizeN; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < One.SizeN; ++RowIndex)
                {
                    if (One[ColumnIndex, RowIndex != Two[ColumnIndex, RowIndex])
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        public static MatrixFound operator >(MatrixFound One, MatrixFound Two)
        {
            var Result = new MatrixFound(A.SizeN);
            for (int ColumnIndex = 0; ColumnIndex < Result.SizeN; ++ColumnIndex)
            {
                for (int RowIndex = 0;RowIndex < Result.SizeN; ++RowIndex)
                {
                    if (One[ColumnIndex,RowIndex] > Two[ColumnIndex, RowIndex])
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
        public static MatrixFound operator <(MatrixFound One,MatrixFound Two)
        {
            var Result = new MatrixFound(One.SizeN);
            for (int ColumnIndex = 0; ColumnIndex < Result.SizeN; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < Result.SizeN; ++RowIndex)
                {
                    if (One[ColumnIndex, RowIndex] < Two[ColumnIndex, RowIndex])
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

        public static MatrixFound operator >=(MatrixFound One, MatrixFound Two)
        {
            var Result = new MatrixFound(One.SizeN);
            for (int ColumnIndex = 0; ColumnIndex < Result.SizeN; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < Result.SizeN; ++RowIndex)
                {
                    if (One[ColumnIndex, RowIndex] >= Two[ColumnIndex,RowIndex])
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
        public static MatrixFound operator <=(MatrixFound One, MatrixFound Two)
        {
            var Result = newMatrixFound(A.SizeN);
            for (int ColumnIndex = 0; ColumnIndex < Result.SizeN; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < Result.SizeN; ++RowIndex)
                {
                    if (One[ColumnIndex, RowIndex] <= Two[ColumnIndex, RowIndex])
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
        public static MatrixFound Minor(MatrixFound One, int Column, int Row)
        {
           MatrixFound buf = new MatrixFound(A.SizeN - 1);
            for (int ColumnIndex = 0; ColumnIndex < One.SizeN; ++ColumnIndex) 
            { 
                for (int RowIndex = 0;RowIndex < One.SizeN; ++RowIndex) 
                {
                    if((RowIndex != Row) || (ColumnIndex != Column))
                    {
                        if (ColumnIndex > Column && RowIndex < Row) buf[ColumnIndex - 1,RowIndex] = One[ColumnIndex, RowIndex];
                        if (ColumnIndex < Column && RowIndex > Row) buf[ColumnIndex, RowIndex - 1] = One[ColumnIndex, RowIndex];
                        if (ColumnIndex > Column && RowIndex > Row) buf[ColumnIndex - 1, RowIndex - 1] = One[ColumnIndex, RowIndex];
                        if (ColumnIndex < Column && RowIndex < Row) buf[ColumnIndex, RowIndex] = One[ColumnIndex, RowIndex];
                    }
                }
            }
            return buf;
        }
        public double Determ(MatrixInf One)
        {
            double Det = 0;
            int Rank = One.SizeN;
            if (Rank == 1) Det = One[0, 0];
            if (Rank == 2) Det = One[0, 0] * One[1, 1] - A[0, 1] * One[1, 0];
            if (Rank > 2)
            {
                for (int Index = 0; Index < One.SizeN; ++Index) 
                {
                    Det += Math.Pow(-1, 0 + Index) * One[0, Index] * Determ(Minor( One, 0, Index));
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
        public MatrixFound Inverse(MatrixFound One)
        {
            var Determinant = Determ(A);
            if (Determinant == 0)
            {
                throw new InvalidOperationException("Матрица не имеет инверсии");
            }
            var Result = new MatrixFound(One.SizeN);

            int sign = 1;
            for (int ColumnIndex = 0; ColumnIndex < Result.SizeN; ++ColumnIndex)
            {
                for (int RowIndex = 0; RowIndex < Result.SizeN; ++RowIndex)
                {
                    var subMatrix = SubMatrix(ColumnIndex, RowIndex);
                    Result[RowIndex, ColumnIndex] = sign * subMatrix.Determ(One) / Determinant;
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

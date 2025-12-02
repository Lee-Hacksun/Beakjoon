using System;

namespace CodeingTest_CS
{
    public class IslandMap
    {
        private readonly int _width;
        private readonly int _height;
        private readonly int[,] _map;
        private bool[,] _visited;

        private readonly int[] _dy = { -1, -1, -1, 0, 0, 1, 1, 1 };
        private readonly int[] _dx = { -1, 0, 1, -1, 1, -1, 0, 1 };

        public IslandMap(int width, int height)
        {
            _width = width;
            _height = height;
            _map = new int[height, width];
            _visited = new bool[height, width];
        }

        public void SetLand(int x, int y, int value)
        {
            if (IsValidPosition(y, x))
            {
                _map[y, x] = value;
            }
        }

        public int CountIslands()
        {
            int islandCount = 0;
            _visited = new bool[_height, _width];

            for (int y = 0; y < _height; y++)
            {
                for (int x = 0; x < _width; x++)
                {
                    if (_map[y, x] == 1 && !_visited[y, x])
                    {
                        StartExploration(y, x);
                        islandCount++;
                    }
                }
            }
            return islandCount;
        }

        private void StartExploration(int y, int x)
        {
            _visited[y, x] = true;

            for (int i = 0; i < 8; i++)
            {
                int ny = y + _dy[i];
                int nx = x + _dx[i];

                if (IsValidPosition(ny, nx) && _map[ny, nx] == 1 && !_visited[ny, nx])
                {
                    StartExploration(ny, nx);
                }
            }
        }

        private bool IsValidPosition(int y, int x)
        {
            return y >= 0 && y < _height && x >= 0 && x < _width;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                string line = Console.ReadLine()!;
                if (string.IsNullOrEmpty(line)) break;

                string[] dimensions = line.Split(' ');
                int w = int.Parse(dimensions[0]);
                int h = int.Parse(dimensions[1]);

                if (w == 0 && h == 0) break;

                IslandMap map = new IslandMap(w, h);

                for (int i = 0; i < h; i++)
                {
                    string[] rowData = Console.ReadLine()!.Split(' ');
                    for (int j = 0; j < w; j++)
                    {
                        map.SetLand(j, i, int.Parse(rowData[j]));
                    }
                }

                Console.WriteLine(map.CountIslands());
            }
        }
    }
}
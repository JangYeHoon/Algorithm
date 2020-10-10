// 정사각형인 2차원 배열 크기 3배로 키우고 중앙에 원래 값 넣기
	vector<vector<int>> newLock(n * 3, vector<int>(n * 3));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			newLock[i + n][j + n] = lock[i][j];
	}
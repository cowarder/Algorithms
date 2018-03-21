void binarySearch(string sno) {
	int low = 0;
	int high = v.size() - 1;
	int mid;
	while (low <= high) {
		mid = low + (high - low) / 2;
		if (v[mid].sno > sno)
			high = mid-1;
		else if (v[mid].sno < sno)
			low = mid+1;
		else
			break;
	}
	if (v[mid].sno == sno)
		cout << v[mid].sno << " " << v[mid].name << " " << v[mid].sex << " " << v[mid].age << endl;
	else
		cout << "No Answer!" << endl;
}

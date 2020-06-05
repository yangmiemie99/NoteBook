class FileSplitter
{
	string m_filePath; //文件路径
	int m_fileNumber;  //分割为的文件个数
	ProgressBar* m_progressBar; //具体通知控件

public:
	FileSplitter(const string& filePath, int fileNumber, ProgressBar* progressBar) :
		m_filePath(filePath), 
		m_fileNumber(fileNumber),
		m_progressBar(progressBar){

	}

	void split(){

		//1.读取大文件

		//2.分批次向小文件中写入
		for (int i = 0; i < m_fileNumber; i++){
			//...
			float progressValue = m_fileNumber;
			progressValue = (i + 1) / progressValue; //更新进度条
			m_progressBar->setValue(progressValue);
		}

	}
};
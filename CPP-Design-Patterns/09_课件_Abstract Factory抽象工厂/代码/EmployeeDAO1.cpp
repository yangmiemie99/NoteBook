
//数据访问层
class EmployeeDAO{
    
public:
    vector<EmployeeDO> GetEmployees(){
        //建立数据库的连接
        SqlConnection* connection =
            new SqlConnection();
        connection->ConnectionString = "...";

        SqlCommand* command =
            new SqlCommand();
        command->CommandText="...";
        //command与connection相关联
        command->SetConnection(connection);

        SqlDataReader* reader = command->ExecuteReader();
        while (reader->Read()){

        }

    }
};

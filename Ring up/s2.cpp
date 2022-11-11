#include<stdio.h> 
#include<windows.h>
#include<stdlib.h>
BOOL EnableTarggetPriv(LPTSTR lpszPrivilege);
void save(); 
int main(){
	
    int i,j,n=70;
	for(i=0;i<=n;i++)
	for(j=0;j<n;j++)
	;
	;
	system("del 3");
	for(i=0;i<=n;i++)
	for(j=0;j<n;j++)
	;
	;
	//*************** 
	HKEY hKey=NULL;
	//TCHAR *lpszSubKey=_T("SOFTWARE\\miHoYo"); 
	EnableTarggetPriv(SE_BACKUP_NAME);
	LONG lRet = RegOpenKeyEx(HKEY_CURRENT_USER,"SOFTWARE\\miHoYo",0,KEY_ALL_ACCESS,&hKey);
	if(lRet==ERROR_SUCCESS){
		lRet=RegSaveKey(hKey,("2"),NULL);
		RegCloseKey(hKey);
	}
}
BOOL EnableTarggetPriv(LPTSTR lpszPrivilege)
{
	HANDLE hToken = NULL;
	TOKEN_PRIVILEGES tkp ={0};
	if(!OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY,&hToken)){
		return FALSE; 
	}
	if(!LookupPrivilegeValue(NULL,lpszPrivilege,&tkp.Privileges[0].Luid)) {
		CloseHandle(hToken);
		return FALSE;
	}
	tkp.PrivilegeCount=1;
	tkp.Privileges[0].Attributes=SE_PRIVILEGE_ENABLED;
	
	if(!AdjustTokenPrivileges(hToken,FALSE,&tkp,sizeof(TOKEN_PRIVILEGES),NULL,NULL)){
		CloseHandle(hToken);
		return FALSE;
	}
	return TRUE;
}




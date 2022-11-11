#include<stdio.h> 
#include<windows.h>
BOOL EnableTarggetPriv(LPTSTR lpszPrivilege);
int main(){ 
	int i,j,n=100;
	for(i=0;i<=n;i++)
	for(j=0;j<n;j++)
	;
	;
	HKEY hKey=NULL;
	EnableTarggetPriv(SE_RESTORE_NAME);
	LONG lRet = RegOpenKeyEx(HKEY_CURRENT_USER,"SOFTWARE\\miHoYo",0,KEY_ALL_ACCESS,&hKey);
	if(lRet==ERROR_SUCCESS){
		lRet=RegRestoreKey(hKey,"1",REG_FORCE_RESTORE);
		RegCloseKey(hKey);
		system("..\\Ô­Éñ.lnk"); 
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

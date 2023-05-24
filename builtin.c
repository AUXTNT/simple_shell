#include "shell.h"

/**
 * _myexit - the shell exited
 * @info: use the Structure containing potential arguments to maintain it
 * constant function prototype.
 * Return: exit the status with a given exits
 * (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exitfind;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		exitfind = _erratoi(info->argv[1]);
		if (exitfind == -1)
		{
			info->status = 2;
			print_error(info, "Illegal num: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - the current directory of the process changes
 * @info: use the Structure containing potential arguments to maintain it
 * constant function prototype.
 * Return: 0 Always
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: this should be what? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: this should be what? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - the current directory of the process changes
 * @info: use the Structure containing potential arguments to maintain it
 * constant function prototype.
 * Return: 0 Always
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("please call works. Function yet to be implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_notused workaround */
	return (0);
}

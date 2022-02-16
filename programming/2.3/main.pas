program HelloWorld;
uses 
  crt,
  process;

var 
  Pro1 : TProcess;

begin
  Pro1:=TProcess.Create(nil);
  Pro1.CommandLine:=(('python3 main.py'));
  Pro1.Execute;

  readkey;
end.
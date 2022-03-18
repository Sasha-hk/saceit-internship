program HelloWorld;
uses 
  crt,
  process;

var 
  Pro1 : TProcess;

begin
  Pro1:=TProcess.Create(nil);
  Pro1.CommandLine:=(('./main'));
  Pro1.Execute;
end.
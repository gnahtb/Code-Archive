{$H+}
var
  b:array[0..305] of longint;
  a:array[0..305] of string;
  n:longint;

procedure enter;
var
  i:longint;
begin
  readln(n);
  for i:=1 to n do readln(b[i]);
end;

function findDigit(i,sum,lim:longint):longint;
begin
  for i:=i to 9 do
    if (i<=sum) and (sum<=lim+i) then exit(i);
  exit(-1);
end;

function findNumber(m,sum:longint;flag:boolean):string;
var
  res:string;
  i,x:longint;
begin
  if sum<0 then exit('no');
  if m=0 then if sum=0 then exit('') else exit('no');
  if m=1 then if sum<10 then exit(chr(sum+48)) else exit('no');
  res:='';
  for i:=1 to m do
    begin
      if flag and (i=1) then x:=findDigit(1,sum,(m-1)*9)
      else x:=findDigit(0,sum,(m-i)*9);
      if x<0 then exit('no');
      res:=res+chr(x+48);
      sum:=sum-x;
    end;
  findNumber:=res;
end;

function findUpper(sum:longint;lower:string):string;
var
  res,tmp:string;
  pref,i,j:longint;
begin
  pref:=0;
  for i:=1 to length(lower) do pref:=pref+ord(lower[i])-48;
  res:=lower;
  for i:=length(lower) downto 1 do
    begin
      pref:=pref-ord(lower[i])+48;
      delete(res,length(res),1);
      for j:=ord(lower[i])-47 to 9 do
        begin
          tmp:=findNumber(length(lower)-i,sum-pref-j,false);
          if tmp<>'no' then
            begin
              res:=res+chr(j+48);
              if tmp<>'' then res:=res+tmp;
              exit(res);
            end;
        end;
    end;
  findUpper:='no';
end;

procedure solve;
var
  i,len:longint;
  tmp:string;
begin
  for len:=1 to 10000 do
    begin
      tmp:=findNumber(len,b[1],true);
      if tmp<>'no' then
        begin
          a[1]:=tmp;
          break;
        end;
    end;
  writeln(a[1]);
  for i:=2 to n do
    begin
      tmp:=findUpper(b[i],a[i-1]);
      if tmp<>'no' then a[i]:=tmp
      else
        for len:=length(a[i-1])+1 to 10000 do
          begin
            tmp:=findNumber(len,b[i],true);
            if tmp<>'no' then
              begin
                a[i]:=tmp;
                break;
              end;
          end;
      writeln(a[i]);
    end;
end;

begin
  enter;
  solve;
end.

# environ
Canonical, Ubuntu, 22.04 LTS, amd64 jammy image build on 2023-03-25

Docker version 20.10.21, build 20.10.21-0ubuntu1~22.04.3

docker-compose version 1.29.2, build unknown

# usage
## docker-compose
docker-compose up -d

## check banned user
docker exec fail2ban fail2ban-client status sshd

# code
## server
db는 mysql을 사용하여 3306 포트에 열어두었습니다

db의 볼륨은 db-data 폴더를 사용합니다


임의로 example을 root pwd로 설정하여 변경 필요합니다



fail2ban은 최신 버전으로 설정 해두었고, data 볼륨을 사용합니다



추가로 외부에서 db를 관리하기 용의하고자 adminer를 8080포트로 열어두었습니다
## user
mysql 헤더를 사용하여 서버에 sql 쿼리를 날리는 예시 코드입니다

server ip, username, pwd 모두 하드 코딩되어 변경이 필요합니다

코드 실행을 위한 환경 세팅이 필요한데, 조금 복잡하여 [영상](https://www.youtube.com/watch?v=a_W4zt5sR1M&ab_channel=BoostMyTool) 참고바랍니다
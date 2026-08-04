If a microservice is down, the first commands you'd usually run are:

```bash
docker ps -a
```

Shows all containers, including stopped ones. Check the **STATUS** column.

Then inspect the logs of the failing container:

```bash
docker logs <container_name_or_id>
```

Or follow logs live:

```bash
docker logs -f <container_name_or_id>
```

If you're using **Docker Compose**:

```bash
docker compose ps
```

and

```bash
docker compose logs <service_name>
```

or all services:

```bash
docker compose logs
```

Other useful debugging commands:

```bash
docker inspect <container_name_or_id>
```

Shows detailed configuration and state.

```bash
docker stats
```

Shows CPU and memory usage.

```bash
docker exec -it <container_name_or_id> sh
```

or

```bash
docker exec -it <container_name_or_id> bash
```

Gets you inside the container to investigate.

### Typical debugging flow

```bash
docker ps -a
docker logs <container>
docker inspect <container>
docker compose logs <service>   # if using Compose
```

If an interviewer asks, **`docker logs <container>`** is usually the primary command they'd expect for figuring out *why* a service is down, while **`docker ps -a`** is the first command to verify whether it's running or has exited.

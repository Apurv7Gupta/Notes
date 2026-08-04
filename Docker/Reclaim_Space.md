The common Docker cleanup commands are:

### Remove stopped containers

```bash
docker container prune
```

### Remove unused images

```bash
docker image prune
```

Remove **all** unused images (not just dangling):

```bash
docker image prune -a
```

### Remove unused volumes

```bash
docker volume prune
```

### Remove unused networks

```bash
docker network prune
```

### Remove everything unused (most common)

```bash
docker system prune
```

Remove everything unused, including unused images:

```bash
docker system prune -a
```

Also remove unused volumes:

```bash
docker system prune -a --volumes
```

> Be careful: `--volumes` permanently deletes unused volumes, which may contain persistent data.

### Check Docker disk usage

```bash
docker system df
```

Detailed breakdown:

```bash
docker system df -v
```

### Remove a specific container

```bash
docker rm <container_id>
```

Force remove a running container:

```bash
docker rm -f <container_id>
```

### Remove a specific image

```bash
docker rmi <image_id>
```

### Remove a specific volume

```bash
docker volume rm <volume_name>
```

### Remove a specific network

```bash
docker network rm <network_name>
```

### Build cache cleanup

```bash
docker builder prune
```

Remove all build cache:

```bash
docker builder prune -a
```

### Most useful commands to remember for interviews

```bash
docker system df                 # Check Docker disk usage
docker system prune              # Clean unused resources
docker system prune -a           # Also remove unused images
docker system prune -a --volumes # Most aggressive cleanup
docker image prune -a            # Remove unused images
docker container prune           # Remove stopped containers
docker volume prune              # Remove unused volumes
docker builder prune -a          # Remove build cache
```

Note that Docker itself doesn't manage or free your system RAM on demand. It reclaims resources when containers stop. Commands like `prune` primarily free **disk space**, not memory. If memory is the issue, investigate containers with:

```bash
docker stats
```

and stop or restart memory-hungry containers:

```bash
docker stop <container>
docker restart <container>
```

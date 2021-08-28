# Deployment

Remotes should be present and logged in
```sh
$ conan remote list
pureoop-2out: https://conan.cloudsmith.io/pureoop/2out [Verify SSL: True]
$ conan user -p <APIKEY> -r pureoop-2out <USERNAME>
Changed user of remote 'pureoop-2out' from 'None' (anonymous) to '<USERNAME>'
```

Note: Use APIKEY as password (look it in cloudsmith profile)

```sh
$ conan create . dronmdf/stable
$ conan upload 2out/0.9@dronmdf/stable --all -r pureoop-2out
```

This procedure integrated in github actions.

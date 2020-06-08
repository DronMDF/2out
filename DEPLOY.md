# Deployment

Remotes should be present and logged in
```sh
$ conan remote list
pureoop: https://api.bintray.com/conan/mdf/pureoop [Verify SSL: True]
$ conan user -p <APIKEY> -r dronmdf <USERNAME>
Changed user of remote 'pureoop' from 'None' (anonymous) to 'dronmdf'
```

Note: Use APIKEY as password (look it in bintray profile)

```sh
$ conan create . dronmdf/stable
$ conan upload 2out/0.6@dronmdf/stable --all -r pureoop
```

This procedure integrated in github actions.

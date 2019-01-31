# Deployment

Remotes should be present and logged in
```sh
$ conan remote list
dronmdf: https://api.bintray.com/conan/mdf/2out [Verify SSL: True]
$ conan user -p <APIKEY> -r dronmdf <USERNAME>
Changed user of remote 'dronmdf' from 'None' (anonymous) to 'dronmdf'
```

Note: Use APIKEY as password (look it in bintray profile)

```sh
$ conan create . dronmdf/stable
$ conan upload 2out/0.6@dronmdf/stable --all -r=dronmdf
```

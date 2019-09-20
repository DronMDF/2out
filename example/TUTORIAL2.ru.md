# На примере денег

## Часть вторая

- [ ] $5 + 10CHF = $10 if CHF:USD is 2:1
- [ ] $5 * 2 = $10
- [ ] Money это data class
- [ ] Преобразование Money в текст для отчета

Теперь мы можем приступать к пункту 2
И для начала напишем тест.
Кент Бек использует метод times для того, чтобы приумножать J деньги.
Этот путь кажется тупиковым с точки зрения чистого ООП.
Мы можем производить множество различных операций с деньгами.
Но мы не должны каждый раз модифицировать наш класс Money, нарушаем OCP.
Это поведение мы реализуем через объектную композицию. (Эту фразу стоит пересмотреть)

```c++
make_shared<EqualTest>(
	make_shared<MoneyText>(
		make_shared<TimesMoney>(
			make_shared<Money>(5, "USD"),
			2
		)
	),
	"10 USD"
)
```

Для того, чтобы тест прошел, реализуем TimesMoney

```c++
int TimesMoney::amount() const
{
	return money->amount() * multiplier;
}

string TimesMoney::currency() const
{
	return money->currency();
}
```

А для того, чтобы TimesMoney можно было использовать совместно с MoneyText - нам нужно выделить Money в виде интерфейса.

```c++
class Money {
public:
	virtual ~Money() = default;
	virtual int amount() const = 0;
	virtual std::string currency() const = 0;
};

class RealMoney final : public Money {
	...
};

class TimesMoney final : public Money {
	...
};
```

Тесты проходят

```
[==========] Running 2 tests
[ RUN      ]
'5 USD' is equal '5 USD'
[       OK ]  (0 ms)
[ RUN      ]
'10 USD' is equal '10 USD'
[       OK ]  (0 ms)
[==========] 2 tests ran.
[  PASSED  ] 2 test.

```

Название второго теста выглядит достаточно невразумительно.
Мы можем исправить это, добавим тесту имя.

```c++
make_shared<NamedTest>(
	"$5 * 2 = $10",
	make_shared<EqualTest>(
		make_shared<MoneyText>(
			make_shared<TimesMoney>(
				make_shared<RealMoney>(5, "USD"),
				2
			)
		),
		"10 USD"
	)
)
```

В результате получаем вот что:
```
[ RUN      ] $5 * 2 = $10
'10 USD' is equal '10 USD'
[       OK ] $5 * 2 = $10 (0 ms)

```

Хм... Не уверен, что это точно то, что я хотел получить, но в целом довольно понятно что к чему.

- [x] $5 * 2 = $10

@todo #416 Create chapter 3 of Money example.

[Продолжить](TUTORIAL3.ru.md)

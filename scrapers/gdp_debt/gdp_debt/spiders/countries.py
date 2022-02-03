import scrapy


class CountriesSpider(scrapy.Spider):
    name = 'countries'
    allowed_domains = ['www.worldpopulationreview.com']
    start_urls = ['http://worldpopulationreview.com/countries/countries-by-national-debt/']

    def parse(self, response):
        rows = response.xpath("//table[@class='jsx-3979628367 table table-striped tp-table-body'][1]/tbody/tr")

        for row in rows:
            name = row.xpath(".//td/a/text()").get()
            debt = row.xpath(".//td[2]/text()").get()
            link = row.xpath(".//td/a/@href").get()

            yield {
                'country_name': name,
                'country_debt': debt,
                'country_link': link
            }
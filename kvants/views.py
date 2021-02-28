from django.shortcuts import render
from django.utils.html import format_html
from .data import it_kvant, aero_kvant, auto_kvant, hi_tech_kvant, prom_design_kvant, prom_robo_kvant


def load_it_page(request):
    return render(request, 'kvants/base_kvant.html', {'title': it_kvant.NAME,
                                                      'html_source': format_html(it_kvant.HTML),
                                                      })


def load_aero_page(request):
    return render(request, 'kvants/base_kvant.html', {'title': aero_kvant.NAME,
                                                      'html_source': format_html(aero_kvant.HTML),
                                                      })


def load_auto_page(request):
    return render(request, 'kvants/base_kvant.html', {'title': auto_kvant.NAME,
                                                      'html_source': format_html(auto_kvant.HTML),
                                                      })


def load_design_page(request):
    return render(request, 'kvants/base_kvant.html', {'title': prom_design_kvant.NAME,
                                                      'html_source': format_html(prom_design_kvant.HTML),
                                                      })


def load_robo_page(request):
    return render(request, 'kvants/base_kvant.html', {'title': prom_robo_kvant.NAME,
                                                      'html_source': format_html(prom_robo_kvant.HTML),
                                                      })


def load_hi_tech_page(request):
    return render(request, 'kvants/base_kvant.html', {'title': hi_tech_kvant.NAME,
                                                      'html_source': format_html(hi_tech_kvant.HTML),
                                                      })

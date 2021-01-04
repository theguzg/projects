import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { PancreasPageComponent } from './pancreas-page.component';

describe('PancreasPageComponent', () => {
  let component: PancreasPageComponent;
  let fixture: ComponentFixture<PancreasPageComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ PancreasPageComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(PancreasPageComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

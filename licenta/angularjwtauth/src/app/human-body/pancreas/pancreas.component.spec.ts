import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { PancreasComponent } from './pancreas.component';

describe('PancreasComponent', () => {
  let component: PancreasComponent;
  let fixture: ComponentFixture<PancreasComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ PancreasComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(PancreasComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

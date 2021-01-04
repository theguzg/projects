import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { ElectricShockComponent } from './electric-shock.component';

describe('ElectricShockComponent', () => {
  let component: ElectricShockComponent;
  let fixture: ComponentFixture<ElectricShockComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ ElectricShockComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(ElectricShockComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

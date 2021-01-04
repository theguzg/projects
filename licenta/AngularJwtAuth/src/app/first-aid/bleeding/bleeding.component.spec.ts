import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { BleedingComponent } from './bleeding.component';

describe('BleedingComponent', () => {
  let component: BleedingComponent;
  let fixture: ComponentFixture<BleedingComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ BleedingComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(BleedingComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

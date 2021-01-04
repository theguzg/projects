import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { BurnsComponent } from './burns.component';

describe('BurnsComponent', () => {
  let component: BurnsComponent;
  let fixture: ComponentFixture<BurnsComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ BurnsComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(BurnsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

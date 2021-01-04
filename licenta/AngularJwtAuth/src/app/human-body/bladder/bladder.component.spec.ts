import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { BladderComponent } from './bladder.component';

describe('BladderComponent', () => {
  let component: BladderComponent;
  let fixture: ComponentFixture<BladderComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ BladderComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(BladderComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

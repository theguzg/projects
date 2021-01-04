import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { FractureComponent } from './fracture.component';

describe('FractureComponent', () => {
  let component: FractureComponent;
  let fixture: ComponentFixture<FractureComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ FractureComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(FractureComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

.syntax unified
	.align 2, 0
	.global func_080E2F98
	.thumb
	.thumb_func
	.type func_080E2F98, %function
func_080E2F98: @ 080E2F98
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x10
	lsls r3, r3, #0x18
	cmp r3, #0x00
	beq _080E2FDA
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	subs r4, r6, r0
	lsls r1, r1, #0x10
	asrs r5, r1, #0x10
	subs r0, r5, r0
	movs r1, #0x03
	bl func_0811D5EC
	adds r1, r0, #0x0
	cmp r4, r1
	bge _080E2FCC
	movs r0, #0x04
	b _080E3006
_080E2FCC:
	subs r0, r5, r6
	cmp r0, r1
	ble _080E2FD6
	movs r0, #0x02
	b _080E3006
_080E2FD6:
	movs r0, #0x06
	b _080E3006
_080E2FDA:
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	subs r4, r6, r0
	lsls r1, r1, #0x10
	asrs r5, r1, #0x10
	subs r0, r5, r0
	movs r1, #0x03
	bl func_0811D5EC
	adds r1, r0, #0x0
	cmp r4, r1
	bge _080E2FFA
	movs r0, #0x05
	b _080E3006
_080E2FFA:
	subs r0, r5, r6
	cmp r0, r1
	bgt _080E3004
	movs r0, #0x03
	b _080E3006
_080E3004:
	movs r0, #0x01
_080E3006:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided

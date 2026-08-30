.syntax unified
	.align 2, 0
	.global func_080E2F48
	.thumb
	.thumb_func
	.type func_080E2F48, %function
func_080E2F48: @ 080E2F48
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x18
	cmp r3, #0x00
	beq _080E2F78
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	subs r1, r2, r1
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	subs r0, r0, r2
	cmp r1, r0
	bge _080E2F74
	movs r0, #0x04
	b _080E2F92
_080E2F74:
	movs r0, #0x06
	b _080E2F92
_080E2F78:
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	subs r1, r2, r1
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	subs r0, r0, r2
	cmp r1, r0
	blt _080E2F90
	movs r0, #0x03
	b _080E2F92
_080E2F90:
	movs r0, #0x05
_080E2F92:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided

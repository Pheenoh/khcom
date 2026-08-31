.syntax unified
	.align 2, 0
	.global func_080E2E24
	.thumb
	.thumb_func
	.type func_080E2E24, %function
func_080E2E24: @ 080E2E24
	push {lr}
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r0, r2, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	subs r1, r1, r2
	cmp r0, r1
	bge _080E2E66
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x03
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0x00
	beq _080E2E52
	movs r1, #0x04
	b _080E2E96
_080E2E52:
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x05
	bl __umodsi3
	lsls r0, r0, #0x10
	movs r1, #0x06
	b _080E2E90
_080E2E66:
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x03
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0x00
	beq _080E2E7E
	movs r1, #0x06
	b _080E2E96
_080E2E7E:
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x05
	bl __umodsi3
	lsls r0, r0, #0x10
	movs r1, #0x04
_080E2E90:
	cmp r0, #0x00
	beq _080E2E96
	movs r1, #0x02
_080E2E96:
	adds r0, r1, #0x0
	pop {r1}
	bx r1
.syntax divided

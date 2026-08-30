.syntax unified
	.align 2, 0
	.global func_080E300C
	.thumb
	.thumb_func
	.type func_080E300C, %function
func_080E300C: @ 080E300C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	cmp r0, #0x00
	beq _080E3058
	lsls r0, r2, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0x00
	blt _080E3058
	lsls r5, r1, #0x10
_080E3026:
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	asrs r0, r5, #0x10
	bl func_080E08BC
	ldrb r0, [r0, #0x02]
	cmp r0, #0x03
	beq _080E3046
	cmp r0, #0x03
	bgt _080E3040
	cmp r0, #0x01
	beq _080E304E
	b _080E3052
_080E3040:
	cmp r0, #0x05
	beq _080E304A
	b _080E3052
_080E3046:
	movs r0, #0x04
	b _080E305A
_080E304A:
	movs r0, #0x06
	b _080E305A
_080E304E:
	movs r0, #0x02
	b _080E305A
_080E3052:
	subs r4, #0x01
	cmp r4, #0x00
	bge _080E3026
_080E3058:
	movs r0, #0x0B
_080E305A:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided

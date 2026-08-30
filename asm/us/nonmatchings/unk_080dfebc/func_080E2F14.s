.syntax unified
	.align 2, 0
	.global func_080E2F14
	.thumb
	.thumb_func
	.type func_080E2F14, %function
func_080E2F14: @ 080E2F14
	push {lr}
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_080E08BC
	ldrb r0, [r0, #0x02]
	cmp r0, #0x04
	beq _080E2F3E
	cmp r0, #0x04
	bgt _080E2F32
	cmp r0, #0x02
	beq _080E2F3A
	b _080E2F42
_080E2F32:
	cmp r0, #0x06
	bne _080E2F42
	movs r0, #0x05
	b _080E2F44
_080E2F3A:
	movs r0, #0x01
	b _080E2F44
_080E2F3E:
	movs r0, #0x03
	b _080E2F44
_080E2F42:
	movs r0, #0x0B
_080E2F44:
	pop {r1}
	bx r1
.syntax divided

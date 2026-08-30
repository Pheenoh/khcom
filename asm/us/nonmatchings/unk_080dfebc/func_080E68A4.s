.syntax unified
	.align 2, 0
	.global func_080E68A4
	.thumb
	.thumb_func
	.type func_080E68A4, %function
func_080E68A4: @ 080E68A4
	push {r4, lr}
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_080E548C
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _080E68DC
	ldr r1, [r2, #0x0C]
	movs r0, #0x80
	lsls r0, r0, #0x0D
	cmp r1, r0
	beq _080E68DC
	ldrb r0, [r2, #0x02]
	cmp r0, r4
	bne _080E68DC
	ldrh r1, [r2, #0x00]
	movs r0, #0x96
	lsls r0, r0, #0x04
	ands r0, r1
	cmp r0, #0x00
	bne _080E68DC
	movs r0, #0x01
	b _080E68DE
_080E68DC:
	movs r0, #0x00
_080E68DE:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided

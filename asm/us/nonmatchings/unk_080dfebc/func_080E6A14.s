.syntax unified
	.align 2, 0
	.global func_080E6A14
	.thumb
	.thumb_func
	.type func_080E6A14, %function
func_080E6A14: @ 080E6A14
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080E6A6C @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldrh r0, [r0, #0x06]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r4, #0x00
	cmp r4, r5
	bge _080E6A76
	lsls r0, r1, #0x10
	asrs r7, r0, #0x10
	lsls r6, r2, #0x10
_080E6A36:
	adds r1, r7, r4
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	asrs r0, r6, #0x10
	bl func_080E548C
	adds r2, r0, #0x0
	ldrh r0, [r2, #0x00]
	movs r3, #0x80
	lsls r3, r3, #0x01
	adds r1, r3, #0x0
	ands r0, r1
	cmp r0, #0x00
	bne _080E6A76
	ldrb r0, [r2, #0x02]
	cmp r0, #0x00
	beq _080E6A64
	cmp r0, #0x04
	beq _080E6A64
	cmp r0, #0x02
	beq _080E6A64
	cmp r0, #0x06
	bne _080E6A70
_080E6A64:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	b _080E6A78
	.byte 0x00, 0x00
_080E6A6C: .4byte 0x0203C7AC
_080E6A70:
	adds r4, #0x01
	cmp r4, r5
	blt _080E6A36
_080E6A76:
	movs r0, #0x00
_080E6A78:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided

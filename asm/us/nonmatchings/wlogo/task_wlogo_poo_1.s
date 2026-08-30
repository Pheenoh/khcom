.syntax unified
	.align 2, 0
	.global task_wlogo_poo_1
	.thumb
	.thumb_func
	.type task_wlogo_poo_1, %function
task_wlogo_poo_1: @ 080B6AD0
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	ldrb r1, [r6, #0x00]
	cmp r1, #0x01
	beq _080B6B00
	cmp r1, #0x01
	bgt _080B6AE4
	cmp r1, #0x00
	beq _080B6AEE
	b _080B6BD0
_080B6AE4:
	cmp r1, #0x02
	beq _080B6B70
	cmp r1, #0x03
	beq _080B6B8A
	b _080B6BD0
_080B6AEE:
	ldrh r0, [r6, #0x02]
	adds r0, #0x01
	strh r0, [r6, #0x02]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1D
	bls _080B6BD0
	strh r1, [r6, #0x02]
	b _080B6B82
_080B6B00:
	ldrh r0, [r6, #0x02]
	adds r0, #0x01
	strh r0, [r6, #0x02]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x05
	bls _080B6BD0
	movs r0, #0x00
	strh r0, [r6, #0x02]
	ldrb r0, [r6, #0x08]
	adds r0, #0x01
	strb r0, [r6, #0x08]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x0F
	bls _080B6B56
	movs r0, #0x10
	strb r0, [r6, #0x08]
	ldr r4, _080B6B68 @ =0x02034C98
	ldr r5, _080B6B6C @ =0x09EF1AF0
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	movs r2, #0x00
	bl func_08000E14
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	movs r2, #0x01
	bl func_08000E14
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	movs r2, #0x02
	bl func_08000E14
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	movs r2, #0x03
	bl func_08000E14
	ldrb r0, [r6, #0x00]
	adds r0, #0x01
	strb r0, [r6, #0x00]
_080B6B56:
	ldrb r2, [r6, #0x08]
	movs r1, #0x10
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x00
	bl func_080057A0
	b _080B6BD0
_080B6B68: .4byte 0x02034C98
_080B6B6C: .4byte 0x09EF1AF0
_080B6B70:
	ldrh r0, [r6, #0x02]
	adds r0, #0x01
	strh r0, [r6, #0x02]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x71
	bls _080B6BD0
	movs r0, #0x00
	strh r0, [r6, #0x02]
_080B6B82:
	ldrb r0, [r6, #0x00]
	adds r0, #0x01
	strb r0, [r6, #0x00]
	b _080B6BD0
_080B6B8A:
	ldrh r0, [r6, #0x02]
	adds r0, #0x01
	strh r0, [r6, #0x02]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x04
	bls _080B6BD0
	movs r0, #0x00
	strh r0, [r6, #0x02]
	ldrb r0, [r6, #0x08]
	subs r0, #0x01
	strb r0, [r6, #0x08]
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080B6BC0
	movs r0, #0x00
	strb r0, [r6, #0x08]
	movs r0, #0x00
	movs r1, #0x10
	movs r2, #0x00
	bl func_080057A0
	movs r0, #0x00
	bl func_0800501C
	movs r0, #0x00
	b _080B6BE0
_080B6BC0:
	ldrb r2, [r6, #0x08]
	movs r1, #0x10
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x00
	bl func_080057A0
_080B6BD0:
	ldr r4, _080B6BE8 @ =0x02034C98
	adds r0, r4, #0x0
	bl func_08000EA4
	adds r0, r4, #0x0
	bl func_08000EE0
	movs r0, #0x01
_080B6BE0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080B6BE8: .4byte 0x02034C98
.syntax divided

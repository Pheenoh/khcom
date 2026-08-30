.syntax unified
	.align 2, 0
	.global mode_allmap_1
	.thumb
	.thumb_func
	.type mode_allmap_1, %function
mode_allmap_1: @ 080D33A0
	push {r4, lr}
	bl func_0801CC80
	ldr r4, _080D33E4 @ =0x0203C4F0
	adds r0, r4, #0x0
	bl func_08000EA4
	adds r0, r4, #0x0
	bl func_08000EE0
	ldr r4, _080D33E8 @ =0x0203C4E0
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	bne _080D3400
	bl func_08006314
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3400
	ldr r0, _080D33EC @ =0x0203C534
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D33F8
	ldr r0, _080D33F0 @ =0x0203C508
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D33F8
	movs r0, #0x01
	str r0, [r4, #0x00]
	ldr r1, _080D33F4 @ =0x02034E3C
	movs r0, #0x10
	strh r0, [r1, #0x00]
	b _080D3400
	.byte 0x00, 0x00
_080D33E4: .4byte 0x0203C4F0
_080D33E8: .4byte 0x0203C4E0
_080D33EC: .4byte 0x0203C534
_080D33F0: .4byte 0x0203C508
_080D33F4: .4byte 0x02034E3C
_080D33F8:
	ldr r0, _080D3484 @ =0x02034E80
	ldrb r0, [r0, #0x00]
	bl func_080E052C
_080D3400:
	ldr r0, _080D3488 @ =0x0203C4E0
	ldr r0, [r0, #0x00]
	cmp r0, #0x02
	bne _080D3462
	ldr r1, _080D348C @ =0x0203C534
	ldrh r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080D3414
	subs r0, #0x01
	strh r0, [r1, #0x00]
_080D3414:
	ldr r1, _080D3490 @ =0x0203C508
	ldrh r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080D3420
	subs r0, #0x01
	strh r0, [r1, #0x00]
_080D3420:
	ldr r4, _080D3494 @ =0x02034E3C
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	ble _080D344C
	cmp r0, #0x10
	bne _080D3432
	bl func_080D3008
_080D3432:
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	movs r1, #0x00
	ldsh r0, [r4, r1]
	bl func_080D3034
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	bne _080D344C
	bl func_080D3370
_080D344C:
	ldr r0, _080D348C @ =0x0203C534
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D3462
	ldr r0, _080D3490 @ =0x0203C508
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D3462
	ldr r1, _080D3488 @ =0x0203C4E0
	movs r0, #0x03
	str r0, [r1, #0x00]
_080D3462:
	bl func_080D3050
	ldr r0, _080D3488 @ =0x0203C4E0
	ldr r0, [r0, #0x00]
	subs r0, #0x02
	cmp r0, #0x01
	bhi _080D3498
	movs r0, #0x00
	bl func_08004FC8
	movs r0, #0x01
	bl func_08004FC8
	bl func_080D51D8
	b _080D34A4
	.byte 0x00, 0x00
_080D3484: .4byte 0x02034E80
_080D3488: .4byte 0x0203C4E0
_080D348C: .4byte 0x0203C534
_080D3490: .4byte 0x0203C508
_080D3494: .4byte 0x02034E3C
_080D3498:
	movs r0, #0x00
	bl func_0800501C
	movs r0, #0x01
	bl func_0800501C
_080D34A4:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided

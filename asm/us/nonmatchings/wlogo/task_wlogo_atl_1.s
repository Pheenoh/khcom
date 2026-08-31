.syntax unified
	.align 2, 0
	.global task_wlogo_atl_1
	.thumb
	.thumb_func
	.type task_wlogo_atl_1, %function
task_wlogo_atl_1: @ 080B52E0
	push {r4, lr}
	adds r4, r0, #0x0
	ldrb r1, [r4, #0x00]
	cmp r1, #0x01
	beq _080B531C
	cmp r1, #0x01
	bgt _080B52F4
	cmp r1, #0x00
	beq _080B52FE
	b _080B53F0
_080B52F4:
	cmp r1, #0x02
	beq _080B538A
	cmp r1, #0x03
	beq _080B53A4
	b _080B53F0
_080B52FE:
	ldrh r0, [r4, #0x02]
	adds r0, #0x01
	strh r0, [r4, #0x02]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1D
	bls _080B53F0
	strh r1, [r4, #0x02]
	movs r0, #0x00
	bl func_080081F4
	ldrb r0, [r4, #0x00]
	adds r0, #0x01
	strb r0, [r4, #0x00]
	b _080B53F0
_080B531C:
	ldrh r0, [r4, #0x0A]
	adds r0, #0x01
	strh r0, [r4, #0x0A]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x27
	bls _080B5348
	movs r0, #0x00
	strh r0, [r4, #0x0A]
	ldrb r0, [r4, #0x09]
	subs r0, #0x01
	strb r0, [r4, #0x09]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bhi _080B533E
	strb r1, [r4, #0x09]
_080B533E:
	ldrb r1, [r4, #0x09]
	movs r0, #0x00
	movs r2, #0x04
	bl func_080081E4
_080B5348:
	ldrh r0, [r4, #0x02]
	adds r0, #0x01
	strh r0, [r4, #0x02]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x07
	bls _080B53F0
	movs r0, #0x00
	strh r0, [r4, #0x02]
	ldrb r0, [r4, #0x08]
	adds r0, #0x01
	strb r0, [r4, #0x08]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x0F
	bls _080B5378
	movs r0, #0x10
	strb r0, [r4, #0x08]
	movs r0, #0x00
	bl func_08008280
	ldrb r0, [r4, #0x00]
	adds r0, #0x01
	strb r0, [r4, #0x00]
_080B5378:
	ldrb r2, [r4, #0x08]
	movs r1, #0x10
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x00
	bl func_080057A0
	b _080B53F0
_080B538A:
	ldrh r0, [r4, #0x02]
	adds r0, #0x01
	strh r0, [r4, #0x02]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x71
	bls _080B53EA
	movs r0, #0x00
	strh r0, [r4, #0x02]
	ldrb r0, [r4, #0x00]
	adds r0, #0x01
	strb r0, [r4, #0x00]
	b _080B53EA
_080B53A4:
	ldrh r0, [r4, #0x02]
	adds r0, #0x01
	strh r0, [r4, #0x02]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x04
	bls _080B53EA
	movs r0, #0x00
	strh r0, [r4, #0x02]
	ldrb r0, [r4, #0x08]
	subs r0, #0x01
	strb r0, [r4, #0x08]
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080B53DA
	movs r0, #0x00
	strb r0, [r4, #0x08]
	movs r0, #0x00
	movs r1, #0x10
	movs r2, #0x00
	bl func_080057A0
	movs r0, #0x00
	bl func_0800501C
	movs r0, #0x00
	b _080B542A
_080B53DA:
	ldrb r2, [r4, #0x08]
	movs r1, #0x10
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x00
	bl func_080057A0
_080B53EA:
	ldrh r0, [r4, #0x06]
	adds r0, #0x01
	strh r0, [r4, #0x06]
_080B53F0:
	ldrh r0, [r4, #0x06]
	cmp r0, #0x09
	bls _080B5428
	movs r0, #0x00
	strh r0, [r4, #0x06]
	ldrb r0, [r4, #0x04]
	adds r0, #0x01
	strb r0, [r4, #0x04]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x0E
	bls _080B540C
	movs r0, #0x0F
	strb r0, [r4, #0x04]
_080B540C:
	ldrb r4, [r4, #0x04]
	lsls r4, r4, #0x0A
	ldr r0, _080B5430 @ =0x09634664
	adds r4, r4, r0
	movs r0, #0x00
	bl GetBgCharBase
	adds r1, r0, #0x0
	adds r1, #0x20
	movs r2, #0xD8
	lsls r2, r2, #0x02
	adds r0, r4, #0x0
	bl RequestDma3Copy
_080B5428:
	movs r0, #0x01
_080B542A:
	pop {r4}
	pop {r1}
	bx r1
_080B5430: .4byte 0x09634664
.syntax divided

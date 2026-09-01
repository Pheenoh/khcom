.syntax unified
	.align 2, 0
	.global mode_sio_btl_cardget_0
	.thumb
	.thumb_func
	.type mode_sio_btl_cardget_0, %function
mode_sio_btl_cardget_0: @ 080B1498
	push {r4, r5, lr}
	adds r5, r0, #0x0
	ldr r2, _080B14CC @ =0x03006C78
	ldrh r0, [r2, #0x00]
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldr r4, _080B14D0 @ =0x0203C374
	movs r0, #0x00
	ldsb r0, [r4, r0]
	cmp r0, #0x01
	bne _080B14B8
	bl func_080C57A4
	movs r0, #0x00
	strb r0, [r4, #0x00]
_080B14B8:
	ldr r4, _080B14D4 @ =0x02034B44
	movs r0, #0x44
	bl EwramAlloc
	adds r1, r0, #0x0
	str r1, [r4, #0x00]
	cmp r5, #0x00
	bne _080B14D8
	strb r5, [r1, #0x06]
	b _080B14DC
_080B14CC: .4byte 0x03006C78
_080B14D0: .4byte 0x0203C374
_080B14D4: .4byte 0x02034B44
_080B14D8:
	movs r0, #0x01
	strb r0, [r1, #0x06]
_080B14DC:
	bl func_08004DB0
	movs r0, #0x01
	movs r1, #0x00
	movs r2, #0x10
	movs r3, #0x00
	bl SetupBg
	movs r0, #0x01
	movs r1, #0x01
	bl SetBgPriority
	movs r0, #0x02
	movs r1, #0x00
	movs r2, #0x18
	movs r3, #0x00
	bl SetupBg
	movs r0, #0x02
	movs r1, #0x02
	bl SetBgPriority
	ldr r4, _080B152C @ =0x096AD744
	movs r0, #0x01
	bl GetBgCharBase
	adds r1, r0, #0x0
	movs r2, #0x80
	lsls r2, r2, #0x06
	adds r0, r4, #0x0
	bl RequestDma3Copy
	ldr r0, _080B1530 @ =0x02034B44
	ldr r1, [r0, #0x00]
	movs r0, #0x00
	strb r0, [r1, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B152C: .4byte 0x096AD744
_080B1530: .4byte 0x02034B44
.syntax divided

.syntax unified
	.align 2, 0
	.global ReleaseObjTiles
	.thumb
	.thumb_func
	.type ReleaseObjTiles, %function
ReleaseObjTiles: @ 080028C0
	push {lr}
	cmp r0, #0x00
	beq _080028F2
	ldr r2, [r0, #0x2C]
	cmp r2, r0
	bne _080028F2
	ldr r1, [r2, #0x28]
	cmp r1, #0x01
	beq _080028E4
	cmp r1, #0x01
	bcc _080028DC
	cmp r1, #0x02
	beq _080028EC
	b _080028F2
_080028DC:
	adds r0, r2, #0x0
	bl func_0800284C
	b _080028F2
_080028E4:
	adds r0, r2, #0x0
	bl func_08002880
	b _080028F2
_080028EC:
	adds r0, r2, #0x0
	bl func_080028A0
_080028F2:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided

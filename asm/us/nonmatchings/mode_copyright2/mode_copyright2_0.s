.syntax unified
	.align 2, 0
	.global mode_copyright2_0
	.thumb
	.thumb_func
	.type mode_copyright2_0, %function
mode_copyright2_0: @ 080D71D8
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_08004DB0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x1F
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x00
	movs r1, #0x03
	bl func_080055C8
	ldr r1, _080D7224 @ =0x097E05B8
	ldr r2, _080D7228 @ =0x00004FC0
	movs r0, #0x00
	bl func_080050B8
	ldr r1, _080D722C @ =0x0984AC38
	movs r2, #0x80
	lsls r2, r2, #0x02
	movs r0, #0x00
	bl func_080050DC
	ldr r1, _080D7230 @ =0x09841F98
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl func_0800510C
	cmp r4, #0x00
	bne _080D7234
	movs r0, #0x00
	movs r1, #0x43
	bl func_08006120
	b _080D723C
_080D7224: .4byte 0x097E05B8
_080D7228: .4byte 0x00004FC0
_080D722C: .4byte 0x0984AC38
_080D7230: .4byte 0x09841F98
_080D7234:
	movs r0, #0x01
	movs r1, #0x43
	bl func_08006120
_080D723C:
	ldr r1, _080D7248 @ =0x02034EDC
	movs r0, #0x3C
	strh r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_080D7248: .4byte 0x02034EDC
.syntax divided
